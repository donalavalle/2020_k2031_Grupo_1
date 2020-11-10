%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AnalizadorSemantico.h"

#include <stddef.h>
#include <stdint.h> 

#define sonIguales(a, b) (strcmp(tipoDeDato(a), tipoDeDato(b)) == 0)

#define tipoDeDato(x) _Generic((x),           \
         char: "char",                        \
     unsigned: "unsigned",                    \
          int: "int",         long: "long",   \
        float: "float",     double: "double", \
       char *: "char",                        \
      default: "other")

#define YYDEBUG 1

int yylex ();
int yyerror (char*);

char* tipoDeDatoGlobal = NULL;
union TipoValor valorTemporal;

FILE* yyin;
FILE* yyout;

%}

%token <entero> ENTERO 
%token <real>   REAL
%token <string> CHAR 
%token <string> STRING
%token <string> TIPO_DATO
%token <string> IDENTIFICADOR

%union {
    int entero;
    float real;
    char* string;
}

%%

input:   /* vacio */
       | input line
;

line:   declaracion
      | asignacion
      | ENTERO
; 

asignacion: IDENTIFICADOR '=' valor ';'  {  /* Simbolo* aux = devolverSimbolo($1);
                                            if(aux) {
                                              if(! strcmp(aux->tipoDato, tipoDeDatoGlobal))
                                                cambiarValor(aux, valorTemporal);
                                              else
                                                fprintf(yyout, "No coinciden los tipos de datos.\n");
                                            }
                                            else
                                              fprintf(yyout, "La variable \'%s\' no fue declarada.\n", $1); */}
;

declaracion:      TIPO_DATO tipoDeclaracion ';' 
;

tipoDeclaracion:     IDENTIFICADOR asignacionOPC 
                   | IDENTIFICADOR asignacionOPC ',' tipoDeclaracion
;

asignacionOPC:  /* VACIO */
                | '=' valor 
;


valor:   ENTERO   { tipoDeDatoGlobal = strdup(tipoDeDato($1)); valorTemporal.valEnt = $1;          }
       | REAL     { tipoDeDatoGlobal = strdup(tipoDeDato($1)); valorTemporal.valReal = $1;         }
       | CHAR     { tipoDeDatoGlobal = strdup(tipoDeDato($1)); valorTemporal.valChar = strdup($1); }
       | STRING   { tipoDeDatoGlobal = strdup(tipoDeDato($1)); valorTemporal.valChar = strdup($1); }
;
        
%%

Simbolo* tablaSimbolos;

int yyerror (char *mensaje) {  /* Función de error */
  fprintf(yyout, "Error: %s\n", mensaje);
}

void main() {
    #ifdef BISON_DEBUG
       yydebug = 1;
    #endif

    yyin = fopen("Input.txt", "r");
    yyout = fopen("Output.txt", "w");

    

    //Simbolo* nuevoSimbolo = crearSimbolo("int", "octi", TIPO_VAR);
    //mostrarTabla(yyout);
    //puts("\n\n");
    yyparse();
    //mostrarTabla(yyout);

    fclose(yyin);
    fclose(yyout);
}