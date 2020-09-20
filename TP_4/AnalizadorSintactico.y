%{

#include <stdio.h>  
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define YYDEBUG 1

int yylex ();
int yyerror (char*);

unsigned count = 0; 

%}

%token <valorEntero> NUMENT
%token <valorReal> NUMREAL
%token <string> TIPO_DATO
%token <string> ID

%type <valorReal> exp

%left '+' '-'
%left '*' '/'
%left '^'
%left '(' ')'

%union {
  int   valorEntero;
  double valorReal;
  char* string;
}

%%

input:   /* vacio */
       | input line
;

line:   '\n'
      | exp '\n' {printf("El resultado es: %g\n", $<valorReal>1);} 
      | TIPO_DATO listaDeIdentificadores ';' '\n' {printf("Tipo de Dato: \'%s\'\tCantidad de variables: %d\n", $<string>1, count); count = 0;}
      | TIPO_DATO ID prototipoFuncion ';' '\n' {printf("Funcion: \'%s\'\tCantidad de parametros: %d\n", $<string>2, count); count = 0;}

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


listaDeIdentificadores:   identificador
                        | identificador ',' listaDeIdentificadores
;

identificador:   ID         {count++;}
               | ID '=' exp {printf("Identificador: \'%s\'\tValor: %g\n", $<string>1, $<valorReal>3); count++;}
;

prototipoFuncion: '(' parametros ')'
;

parametros:   /* VACIO */
            | parametro      
;   

parametro:   param
           | param ',' parametro
;

param:   TIPO_DATO    {count++;}
       | TIPO_DATO ID {count++;}
;


%%

int yyerror (char *mensaje)  /* Funcion de error */
{
  printf ("Error: %s\n", mensaje);
}

void main(){ 

    //yydebug = 1;
    yyparse();

}