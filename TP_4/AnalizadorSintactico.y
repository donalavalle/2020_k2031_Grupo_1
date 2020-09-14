%{

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define YYDEBUG 1

int yylex ();
int yyerror (char*);

unsigned cont = 0;

%}

%token <valorEntero> NUMENT
%token <valorReal> NUMREAL

%type <valorReal> exp

%union {
  int   valorEntero;
  float valorReal;
  char* string;
}

%%

input:   /* vacio */
       | input line
;

line:   '\n'
      | exp '\n' {printf("El resultado es: %g\n", $<valorReal>1);}
    
;

exp:   NUMENT      {$<valorReal>$ = $<valorEntero>1;}
     | NUMREAL     {$<valorReal>$ = $<valorReal>1;}
     | exp '+' exp {$<valorReal>$ = $<valorReal>1 + $<valorReal>3;}
     | exp '-' exp {$<valorReal>$ = $<valorReal>1 - $<valorReal>3;}
     | exp '*' exp {$<valorReal>$ = $<valorReal>1 * $<valorReal>3;}
     | exp '/' exp {if($<valorReal>3 == 0) {printf("No se puede hacer division entre 0\n"); return 1;} else $<valorReal>$ = $<valorReal>1 / $<valorReal>3;}
     | exp '^' exp {if($<valorReal>1 == 0 && $<valorReal>3 == 0) {printf("No se puede realizar 0^0\n"); return 1;} else $<valorReal>$ = pow ($<valorReal>1, $<valorReal>3);}
     | '-' exp     {$<valorReal>$ = - $<valorReal>2;}
     | '(' exp ')' {$<valorReal>$ = $<valorReal>2;}
;

%%

int yyerror (char *mensaje)  /* Funcion de error */
{
  printf ("Error: %s\n", mensaje);
}

void main(){ 

    //yydebug = 1;

    printf("Ingrese una expresion: ");
    yyparse();

}