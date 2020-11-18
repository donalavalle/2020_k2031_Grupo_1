%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tabla_Simbolos.h"

#include <stddef.h>
#include <stdint.h> 

//[!] Definir funciones con DEFINE, permite no estandarizar el tipo de dato de los parametros [!]. 
#define tipoDeDato(x) _Generic((x), char: "char", int: "int", float: "float", char *: "char*", default: "other") 
#define sonIguales(var1, var2) (! strcmp(tipoDeDato(var1), tipoDeDato(var2))) 

#define YYDEBUG 1

int yylex ();
int yyerror (char*);
void mostrarErrorDeVariable(char*);

char* tipoDeDatoVar   = NULL;
char* tipoDeDatoID    = NULL;
char* tipoDeDatoParam = NULL;

FILE* yyin;
FILE* yyout;

union TipoValor valorTemporal;
Funcion* listaDeParametrosTemporal;

%}

%token <entero>   ENTERO 
%token <real>     REAL
%token <caracter> CHAR 
%token <string>   STRING
%token <string>   TIPO_DATO
%token <string>   IDENTIFICADOR

%union {
    int   entero;
    float real;
    char  caracter;
    char* string;
}

%%

input:   /* Vacío */
       | input line
;

line:   /* Vacío */
      | asignacion  ';' {tipoDeDatoVar = NULL;}
      | declaracion ';' {
                          free(tipoDeDatoID); // [❗] Limpia la lista de parametros temporal para poder reutilizarla en un futuro
                          listaDeParametrosTemporal = NULL;
                        }
; 

asignacion: IDENTIFICADOR '=' valor   {
                                        Simbolo* aux = devolverSimbolo($1);
                                        if(aux) {
                                          if(! strcmp(aux->tipoDato, tipoDeDatoVar)) // [!] Si no hay error de tipo, cambia el valor correctamente.
                                            cambiarValor(aux, valorTemporal);
                                          else 
                                            yyerror("No coinciden los tipos de datos"); 
                                        }
                                        else{
                                          mostrarErrorDeVariable($1);
                                        }
                                      }
;

declaracion: declaradorDeTipo punteroOpcional tipoDeclaracion
;

punteroOpcional:   /* Vacio */
                 | '*'          {
                                  strcat(tipoDeDatoID, "*"); // Concatenación de string, para agregar * al tipo de dato.
                                  strcat(tipoDeDatoParam, "*"); // Concatenación de string, para agregar * al tipo de dato.
                                }
;

declaradorDeTipo: TIPO_DATO   { 
                                tipoDeDatoID = strdup($1);
                                tipoDeDatoParam = strdup($1);
                              } 
;

tipoDeclaracion:     decla
                   | tipoDeclaracion ',' decla
                   | IDENTIFICADOR '(' listaDeParametros ')' {
                                                              Simbolo* aux = devolverSimbolo($1);
                                                              if(! aux){
                                                                aux = crearSimbolo(tipoDeDatoID, $1, TIPO_FUNC); // [❗] Crea un simbolo de tipo FUNCION
                                                                insertarSimbolo(aux);
                                                                aux -> valor . func = listaDeParametrosTemporal;
                                                              } 
                                                              else {
                                                                yyerror("Doble declaración de la variable");
                                                              }
                                                             }
;

decla: IDENTIFICADOR asignacionOPC {
                                      Simbolo* aux = devolverSimbolo($1);
                                      if(! aux){ // [!] Pregunta si el valor no fue declarado anteriormente
                                        // [!] Crea un simbolo nuevo y lo inserta en la TS.
                                        aux = crearSimbolo(tipoDeDatoID, $1, TIPO_VAR);
                                        insertarSimbolo(aux);

                                        if(tipoDeDatoVar){ // [!] Pregunta si existe una inicializacion de la variable
                                          // [!] Si es asi, verifica que los tipos coincidan. Si se cumple, modifica, si no, lanza un error
                                          if(! strcmp(tipoDeDatoID, tipoDeDatoVar))
                                            cambiarValor(aux, valorTemporal);
                                          else
                                            yyerror("El valor asignado no coincide con el tipo de dato declarado");
                                        }

                                        valorTemporal = limpiarUnion(); // [!] Limpio la variable que guarda el valor a asignar
                                      }
                                      else
                                        yyerror("Doble declaración de la variable");
                                   }
;

asignacionOPC:  /* Vacio */
              | '=' valor
;

listaDeParametros:  /* Vacio */
                   | parametro otrosParametros
;

otrosParametros:   /* Vacio */                      
              | ',' parametro otrosParametros
;

parametro: declaradorDeTipo punteroOpcional idOPC {
                                                    insertarParametro(&listaDeParametrosTemporal, tipoDeDatoParam);
                                                  }
;

idOPC:  /* Vacio */
      | IDENTIFICADOR
;

valor:   ENTERO   {
                    // [!] Asigna el tipo de dato del VALOR en la variable global para que posteriormente 
                    //     sea utilizado en la verificacion de tipos :)
                    // [!] Asigna el valor semantico del VALOR en la variable global para luego realizar
                    //     la asignacion correctamente. 
                    tipoDeDatoVar = strdup(tipoDeDato($1));
                    valorTemporal . valEnt = $1;
                  }
       | REAL     {
                    tipoDeDatoVar = strdup(tipoDeDato($1));
                    valorTemporal . valReal = $1;
                  }
       | CHAR     {
                    tipoDeDatoVar = strdup(tipoDeDato($1));
                    valorTemporal . valChar = $1;
                  }
       | STRING   {
                    tipoDeDatoVar = strdup(tipoDeDato($1));
                    valorTemporal . valString = strdup($1);
                  }
;
        
%%

Simbolo* tablaSimbolos;
unsigned cantidadDeLineas = 1;

int yyerror (char *mensaje) {  /* Función de error */
  fprintf(yyout, "\nError en linea %d: %s.\n", cantidadDeLineas, mensaje);
}

void mostrarErrorDeVariable(char* nombreVariable) {
  fprintf(yyout, "\nError: La variable \'%s\' no fue declarada. Linea: %s\n", nombreVariable, cantidadDeLineas);
}

void main() {
    #ifdef BISON_DEBUG
       yydebug = 1;
    #endif

    yyin = fopen("Input.txt", "r");
    yyout = fopen("Reporte.txt", "w");

    /* mostrarTabla(yyout);
    
    Simbolo* nuevoSimbolo = crearSimbolo("int", "unaVariable", TIPO_VAR);
    insertarSimbolo(nuevoSimbolo); */

/*
    nuevoSimbolo = crearSimbolo("char", "b", TIPO_VAR);
    insertarSimbolo(nuevoSimbolo);

    mostrarTabla(yyout); */

    yyparse();

    mostrarTabla(yyout);

    fclose(yyin);
    fclose(yyout);

    /*
       ◼◾ Sentencias simples y compuestas (for, if, while, etc) -> INCLUIDAS EN TP4 ❌
       ◼◾ Declaracion variables y almacenamiento en TS: punteros y arreglos ❌💜
       ◼◾ Declaracion funciones y almacenamiento de TS ❌💜💜💜
       ◼◾ Expresiones (también incluidas dentro de sentencias) ❌
       ◼◾ Control de tipo de datos en alguna operacion binaria ❌
       ◼◾ Control doble declaracion de variables ✅ (casi)
       ◼◾ Control de cantidad y tipo de datos en declaracion de funciones ❌
       ◼◾ ❗❗ GENERAR REPORTE ❗❗: 
              Lista variables declaradas con su tipo ❌
              Lista de funciones declaradas con su tipo (retorno), cantidad y tipo de parametros. ❌
              Errores lexicos (FLEX), sintacticos(TOKEN ERROR) y semanticos (RUTINAS) encontrados. ❌
    */
}