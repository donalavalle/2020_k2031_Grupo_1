%{

#include <stdio.h>
#include "AnalizadorSemantico.h"

#define YYDEBUG 1

int yylex ();
int yyerror (char*);

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
; 

asignacion: IDENTIFICADOR '=' valor ';' {}
;

declaracion:      TIPO_DATO tipoDeclaracion ';' 
;

tipoDeclaracion:     IDENTIFICADOR asignacionOPC 
                   | IDENTIFICADOR asignacionOPC ',' tipoDeclaracion
;

asignacionOPC:  /* VACIO */
                | '=' valor 
;

valor:   ENTERO
       | REAL
       | CHAR 
       | STRING
;
        
%%

Simbolo* tablaSimbolos;

int yyerror (char *mensaje)  /* Funcion de error */
{
  printf("Error: %s\n", mensaje);
}

void main() {
    #ifdef BISON_DEBUG
       yydebug = 1;
    #endif

    yyparse();
}