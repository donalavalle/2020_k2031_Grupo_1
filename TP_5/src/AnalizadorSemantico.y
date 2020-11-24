%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tabla_Simbolos.h"

#include <stddef.h>
#include <stdint.h> 

//[!] Definir funciones con DEFINE, permite no estandarizar el tipo de dato de los parametros. 
#define tipoDeDato(x) _Generic((x), char: "char", int: "int", float: "float", char *: "char*", default: "other")
#define sonIguales(var1, var2) (! strcmp(tipoDeDato(var1), tipoDeDato(var2))) 

#define YYDEBUG 1

int yylex ();
int yyerror (char*);
void ingresarErrorSemantico(char*);
void ingresarErrorSintactico();
void mostrarErrorDeVariable(char*);

unsigned flagErrorExp = 0;
unsigned flagHayPyC = 1;  

char* tipoDeDatoVar   = NULL; // [❗] Variable global utilizada para almacenar el tipo de dato de variables.
char* tipoDeDatoID    = NULL; // [❗] Variable global utilizada para almacenar el tipo de dato de los identificadores.
char* tipoDeDatoParam = NULL; // [❗] Variable global utilizada para almacenar el tipo de dato de los parametros de una funcion.
char* tipoDatoExp     = NULL; // [❗] Variable global utilizada para almacenar el tipo de dato de expresiones.

FILE* yyin;
FILE* yyout;

union TipoValor valorTemporal;        // [❗] Variable global utilizada para almacenar el valor semantico de las constantes (UNION -> ya que cambia dependiendo del tipo de dato).
union TipoValor valorExp;             // [❗] Variable global utilizada para almacenar el valor semantico de las expresiones (UNION -> ya que cambia dependiendo del tipo de dato).
Funcion* listaDeParametrosTemporal;   // [❗] Lista de paramatros global que se utiliza para realizar las rutinas semanticas de una funcion.


%}

%token <entero>   ENTERO 
%token <real>     REAL
%token <caracter> CHAR 
%token <string>   STRING
%token <string>   TIPO_DATO
%token <string>   IDENTIFICADOR

%token IF
%token ELSE
%token DO
%token FOR
%token WHILE
%token CONTINUE
%token BREAK
%token RETURN

%type <tipo> exp;

%union {
    int   entero;
    float real;
    char   caracter;
    char* string;
    
    struct {    // [❗] Declaramos este Struct 'tipo' para que el NT 'exp' pueda almacenar el valor y el tipo de dato según qué regla siga
      union {   
        int      valEnt; 
        double   valReal;
        char     valChar;
        char*    valString;
      } valor; 
    
      char* tipoDato;
    } tipo;
}

%%

input:   /* Vacío */
       | input line
;

line:   /* Vacío */
      | declaAsig
      | sentencia 
; 

declaAsig: | asignacion      {
                          tipoDeDatoVar = NULL;
                        }
           | declaracion     {
                          free(tipoDeDatoID); 
                          listaDeParametrosTemporal = NULL; // [❗] Limpia la lista de parametros temporal para poder reutilizarla en un futuro
                          tipoDeDatoVar = NULL;
                          tipoDatoExp = NULL;
                        }
           | declaracionFuncion
           | llamadoFuncion 
;

sentencia:  sentenciaExp
          | sentenciaComp
          | sentenciaSel
          | sentenciaIter
          | sentenciaSalto puntoComaError {
                                            flagHayPyC = 1;
                                          }
;

sentenciaExp: expOpc puntoComaError {
                                      flagHayPyC = 1;
                                    }
;

expOpc:  /* VACIO */
       | expDeSentencia
;

sentenciaComp: '{' listaComp '}'
;

listaComp:  listaDeclaracionesOpc listaSentenciasOpc
          | listaComp listaDeclaracionesOpc listaSentenciasOpc
;

listaDeclaracionesOpc:  /* VACIO */
                        | listaDeclaraciones
;

listaDeclaraciones:   declaraciones
                    | listaDeclaraciones declaraciones
;

declaraciones:   declaracion
               | llamadoFuncion
               | asignacion
;

listaSentenciasOpc:   /* VACIO */
                      | listaSentencias
;

listaSentencias:  sentencia
                | listaSentencias sentencia
;

sentenciaSel:   IF '(' expDeSentencia ')' sentencia elseOpc
; 

elseOpc:   /* VACIO */
         | ELSE sentencia
;

sentenciaIter:   WHILE '(' expDeSentencia ')' sentencia
               | DO sentencia WHILE '(' expDeSentencia ')' ';'
               | FOR '(' forOpc ';' expOpc ';' expOpc ')' sentencia
;

forOpc:   /* VACIO */
        | declaracion
        | asignacion
; 

sentenciaSalto:   CONTINUE 
                | BREAK
                | RETURN expOpc
;

expDeSentencia: expresion {
                          tipoDatoExp = NULL;
                          valorExp = limpiarUnion()
                        }
;


llamadoFuncion: IDENTIFICADOR '(' argumentos ')' puntoComaError  {
                                                                  if(flagHayPyC){ // [❗] Si hay punto y coma, realiza la accion asociada correspondiente.
                                                                    Simbolo* aux = devolverSimbolo($1);
                                                                    if(aux){
                                                                      if(aux -> tipoID != TIPO_FUNC) // [❗] Pregunta si el identificador es una FUNCION
                                                                        ingresarErrorSemantico("El ID utilizado no corresponde con una funcion");
                                                                      else
                                                                        verificarParametros(aux, listaDeParametrosTemporal, yyout); // [❗] Si es una funcion, verifica que la cantidad y el tipo de los argumentos sea correcta.
                                                                    }
                                                                    else
                                                                      mostrarErrorDeVariable($1);
                                                                      //ingresarErrorSemantico("La variable no fue declarada"); // [❗] Ingresa el mensaje indicado en la lista de errores SEMANTICOS. (No indicamos el nombre de la variable no decalarada) 
                                                                  }

                                                                  flagHayPyC = 1;

                                                                  listaDeParametrosTemporal = NULL; // [❗] Libera la lista temporal.
                                                                }  
;

puntoComaError:   ';'
                | error {
                          flagHayPyC = 0; 
                          insertarError(&erroresSintacticos, "Se esperaba ';' al final de la linea");
                        }
;

argumentos: tipoDeArgumento otroArgumentoOPC
;


tipoDeArgumento:   /* VACIO */
                 | valor       {
                                insertarParametro(&listaDeParametrosTemporal, tipoDeDatoVar);
                               }
;

otroArgumentoOPC:  /* VACIO */
                | ',' argumentos

;

asignacion: IDENTIFICADOR '=' expresion puntoComaError {
                                                          if(flagHayPyC) {
                                                            Simbolo* aux = devolverSimbolo($1); 
                                                            if(aux) { // [❗] Si existe...
                                                              if(aux -> tipoID != TIPO_VAR) // [❗] Pregunta si el identificador es una funcion. 
                                                                ingresarErrorSemantico("El ID utilizado no corresponde con una variable");
                                                              else{
                                                                if(! strcmp(aux -> tipoDato, tipoDatoExp)) // [❗] Si no hay error de tipo, cambia el valor correctamente dependiendo del tipo de dato.
                                                                    cambiarValor(aux, valorExp);
                                                                  else 
                                                                    ingresarErrorSemantico("No coinciden los tipos de datos");
                                                                }
                                                              }
                                                              else
                                                                mostrarErrorDeVariable($1);
                                                          }
                                                              //ingresarErrorSemantico("La variable no fue declarada");
                                                          flagHayPyC = 1;

                                                          valorExp = limpiarUnion();
                                                          tipoDatoExp = NULL;
                                                        }
;

declaracion: declaradorDeTipo punteroOpcional tipoDeclaracion
;

punteroOpcional:   /* Vacio */
                 | '*'          {
                                  strcat(tipoDeDatoID, "*");    // [❗] Concatenación de string, para agregar * al tipo de dato.
                                }
;

declaradorDeTipo: TIPO_DATO   { 
                                tipoDeDatoID = strdup($1);
                              } 
;

tipoDeclaracion:     IDENTIFICADOR asignacionOPC puntoComaError      {
                                                                        if(flagHayPyC){
                                                                          Simbolo* aux = devolverSimbolo($1);
                                                                          if(! aux){ // [❗] Pregunta si el valor no fue declarado anteriormente
                                                                            // [❗] Crea un simbolo nuevo y lo inserta en la TS.
                                                                            aux = crearSimbolo(tipoDeDatoID, $1, TIPO_VAR);
                                                                            insertarSimbolo(aux);

                                                                            if(tipoDatoExp){ // [❗] Pregunta si existe una inicializacion de la variable
                                                                              // [❗] Si es asi, verifica que los tipos coincidan. Si se cumple, modifica, si no, lanza un error
                                                                              if(! strcmp(tipoDeDatoID, tipoDatoExp)) // [❗] Si existe, verifica que el valor de asignacion coincidad con el tipo del identificador.
                                                                                cambiarValor(aux, valorExp);
                                                                              else
                                                                                ingresarErrorSemantico("El valor asignado no coincide con el tipo de dato declarado");
                                                                            }
                                                                          }
                                                                          else
                                                                            ingresarErrorSemantico("Doble declaración de la variable");

                                                                        }
                                                                        
                                                                        flagHayPyC = 1;
                                                                        valorExp = limpiarUnion(); // [❗] Limpio la variable que guarda el valor a asignar para su posterior reutilizacion.
                                                                     }
                   | decla ',' tipoDeclaracion
;
declaracionFuncion: declaradorDeTipo punteroOpcional IDENTIFICADOR '(' listaDeParametros ')' puntoComaError {
                                                                                                              if(flagHayPyC){
                                                                                                                Simbolo* aux = devolverSimbolo($3);
                                                                                                                if(! aux){ // [❗] Pregunta si el identificador no fue utilizado antes.
                                                                                                                  aux = crearSimbolo(tipoDeDatoID, $3, TIPO_FUNC); // [❗] Crea un simbolo de tipo FUNCION
                                                                                                                  insertarSimbolo(aux);
                                                                                                                  aux -> valor . func = listaDeParametrosTemporal; // [❗] Asigna la lista de parametros de la funcion generada previamente.
                                                                                                                } 
                                                                                                                else { // [❗] Si el identifidor ya fue utilizado, lanza error semantico.
                                                                                                                  ingresarErrorSemantico("Doble declaración de la variable");
                                                                                                                };  
                                                                                                              }

                                                                                                              flagHayPyC = 1;                               

                                                                                                              listaDeParametrosTemporal = NULL; // [❗] Limpia la lista temporal para su reutilizacion.
                                                                                                            }
;

decla: IDENTIFICADOR asignacionOPC {
                                      Simbolo* aux = devolverSimbolo($1);
                                      if(! aux){ // [❗] Pregunta si el valor no fue declarado anteriormente
                                        // [❗] Crea un simbolo nuevo y lo inserta en la TS.
                                        aux = crearSimbolo(tipoDeDatoID, $1, TIPO_VAR);
                                        insertarSimbolo(aux);

                                        if(tipoDatoExp){ // [❗] Pregunta si existe una inicializacion de la variable
                                          // [❗] Si es asi, verifica que los tipos coincidan. Si se cumple, modifica, si no, lanza un error
                                          if(! strcmp(tipoDeDatoID, tipoDatoExp)) // [❗] Si existe, verifica que el valor de asignacion coincidad con el tipo del identificador.
                                            cambiarValor(aux, valorExp);
                                          else
                                            ingresarErrorSemantico("El valor asignado no coincide con el tipo de dato declarado");
                                        }
                                      }
                                      else
                                        ingresarErrorSemantico("Doble declaración de la variable");

                                      valorExp = limpiarUnion(); // [❗] Limpio la variable que guarda el valor a asignar para su posterior reutilizacion.
                                   }
;

asignacionOPC:  /* Vacio */
              | '=' expresion            { /* // [❗] Guardo el valor semantico y el tipo de dato de la expresion en variables temporales para realizar las resticciones semant. correspondientes. 
                                          valorExp . valEnt     = $2 . valor . valEnt;
                                          valorExp . valReal    = $2 . valor . valReal;
                                          valorExp . valChar    = $2 . valor . valChar;
                                          valorExp . valString  = $2 . valor . valString;

                                          tipoDatoExp = strdup($2 . tipoDato); */
                                        }
;

listaDeParametros:  /* Vacio */                 {
                                                  insertarParametro(&listaDeParametrosTemporal, "void");
                                                }
                   | parametro otrosParametros
;

otrosParametros:   /* Vacio */                      
              | ',' parametro otrosParametros
;

parametro: declaradorDeTipoParam punteroOpcionalParam idOPC {
                                                              insertarParametro(&listaDeParametrosTemporal, tipoDeDatoParam);
                                                            }
;

declaradorDeTipoParam: TIPO_DATO   { 
                                     tipoDeDatoParam = strdup($1);
                                   } 
;

punteroOpcionalParam:   /* Vacío */ 
                      | '*'         {
                                      strcat(tipoDeDatoParam, "*"); // [❗] Concatenación de string, para agregar * al tipo de dato.
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
       | REAL          {
                        tipoDeDatoVar = strdup(tipoDeDato($1));
                        valorTemporal . valReal = $1;
                       }
       | CHAR          {
                        tipoDeDatoVar = strdup(tipoDeDato($1));
                        valorTemporal . valChar = $1;
                       }
       | STRING        {
                        tipoDeDatoVar = strdup(tipoDeDato($1));
                        valorTemporal . valString = strdup($1);
                       }
       | IDENTIFICADOR {
                        Simbolo* aux = devolverSimbolo($1);

                        if(aux){ // Verifica que el identificador exista para luego obtener su valor semantico.
                          valorTemporal = aux -> valor;
                          tipoDeDatoVar = strdup(aux -> tipoDato);
                        }
                        else
                          mostrarErrorDeVariable($1);
                          //ingresarErrorSemantico("La variable no fue declarada");
                       }
;


expresion: exp {
                  if(flagErrorExp){ // [❗] Si la expresion no es valida, asignara a la variable valores DEFAULT.
                    valorExp.valEnt = 0;
                    valorExp.valReal = 0.0;
                    valorExp.valChar = '\0';
                    valorExp.valString = NULL;

                    tipoDatoExp = NULL;

                    flagErrorExp = 0;
                  }
                  else{ // [❗] Si es valida, asigna los valores correspondientes.
                    valorExp.valEnt    = $1.valor.valEnt;
                    valorExp.valReal   = $1.valor.valReal;
                    valorExp.valChar   = $1.valor.valChar;
                    valorExp.valString = $1.valor.valString;
                    
                    tipoDatoExp = strdup($1.tipoDato);
                  }
               }
;

exp:   valor       {
                      // [❗] Guarda el valor semantico y el tipo de dato dentro de la expresion sea cual sea. 
                      $$ . tipoDato = tipoDeDatoVar;
                      
                      if(tipoDeDatoVar){
                        $$ . valor . valEnt    = valorTemporal . valEnt;
                        $$ . valor . valChar   = valorTemporal . valChar;
                        $$ . valor . valReal   = valorTemporal . valReal;
                        $$ . valor . valString = valorTemporal . valString;
                      }
                   }
     | exp '+' exp {  
                      if($1.tipoDato && $3.tipoDato){
                        if(! strcmp($1 . tipoDato, $3 . tipoDato) && strcmp($1 . tipoDato, "char*")){ // [❗] Verifica que se pueda realizar la suma, es decir, que los valores a sumar sean un mismo tipo y que ninguno sea de tipo char*
                          // [❗] Guarda el valor semantico y el tipo de dato dentro de la expresion "madre" luego de realizar la sumatoria de los valores semanticos
                          $$ . valor . valEnt  = $1 . valor . valEnt  + $3 . valor . valEnt;
                          $$ . valor . valChar = $1 . valor . valChar + $3 . valor . valChar;
                          $$ . valor . valReal = $1 . valor . valReal + $3 . valor . valReal;

                          $$ . tipoDato = $1 . tipoDato; 
                        }
                        else{ // [❗] Lanza un error e iguala todos los campos de la union a valores DEFAULT,.  
                          ingresarErrorSemantico("Los valores no son compatibles");
                          flagErrorExp = 1; // [❗] Flag que permite saber si la expresion es valida
                        }
                      }
                      else
                        flagErrorExp = 1;
                   }
;

%%

Simbolo* tablaSimbolos;

Error* erroresSemanticos;
Error* erroresSintacticos;

unsigned cantidadDeLineas = 1;

void ingresarErrorSemantico(char* mensaje) {
  insertarError(&erroresSemanticos, mensaje);
}

int yyerror (char *mensaje) {  /* Función de error */
  //[❗] COMENTADO para que no haga nada al momento de encontrar un 'syntax error' ya que nos vamos a ocupar de ese error de otra manera (mensaje personalizado). 
}

void mostrarErrorDeVariable(char* nombreVariable) {
  char* mensaje = strdup("La variable '");
  strcat(mensaje, strdup(nombreVariable));
  strcat(mensaje, "' no fue declarada");
  

  ingresarErrorSemantico(mensaje);
  //fprintf(yyout, "\nError en linea %d: La variable \'%s\' no fue declarada\n", cantidadDeLineas, nombreVariable);
  
}

void main() {
    #ifdef BISON_DEBUG
       yydebug = 1;
    #endif

    yyin = fopen("Input.txt", "r");
    yyout = fopen("Reporte.txt", "w");

    yyparse();

    //mostrarTabla(yyout);
    generarReporte(yyout); // [❗] Muestra todos los errores ocurridos junto con las funciones y variables declaradas. 

    fclose(yyin);
    fclose(yyout);

    /* 📚 TO DO LIST 📚 
       ❌ Sentencias simples y compuestas (for, if, while, etc) -> Incluidas En TP4. 
       ❓  Declaracion variables y almacenamiento en TS: punteros y arreglos. (Casi: Faltan arrays). 
       ✅ Declaracion, llamada y almacenamiento en TS de funciones. 
       ✅ Expresiones  (CASI)
       ✅ Control de tipo de datos en alguna operacion binaria.(CASI)
       ✅ Control doble declaracion de variables. 
       ✅ Control de cantidad y tipo de datos en declaracion de funciones.
       ◼◾ (❗❗) GENERAR REPORTE (❗❗): 
          ❓  Lista variables declaradas con su tipo. (Casi: Modificar TS para adaptar a Reporte)
          ❓  Lista de funciones declaradas con su tipo (retorno), cantidad y tipo de parametros. (Casi: Modificar TS para adaptar a Reporte) 
          ❌ Errores lexicos (FLEX), sintacticos(TOKEN ERROR) y semanticos (RUTINAS) encontrados.


      COSAS A MEJORAR:
        ◾ Si faltase ';', en la declaración múltiple solo no va a declarar la ultima variable.
    */

    /*
    valorTemporal1;
    valorTemporal2;

    valorTemporal = valorTemporal1 + valorTemporal2;

    exp:   valor       {valorTemporal;}
         | exp '+' exp {$$ = $1 + $3;}
    ;
    
    */
}