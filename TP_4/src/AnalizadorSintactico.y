%{

#include <stdio.h>  
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define YYDEBUG 1

int yylex ();
int yyerror (char*);

unsigned count = 0; 

FILE* yyin;
FILE* yyout;

%}

%token <valorEntero> NUM_ENTERO
%token <valorReal> NUM_REAL
%token <valorString> TIPO_DATO
%token <valorString> ID
%token ASIG_MULT
%token ASIG_DIV
%token ASIG_MOD
%token ASIG_SUMA
%token ASIG_RESTA
%token ASIG_DESP_IZQ
%token ASIG_DESP_DER
%token ASIG_AND_BIN
%token ASIG_XOR_BIN
%token ASIG_OR_BIN
%token OP_INC
%token OP_DEC
%token OP_IGUALDAD
%token OP_DESIGUALDAD
%token OP_AND
%token OP_OR
%token OP_MENOR_IGUAL
%token OP_MAYOR_IGUAL
%token OP_DESP_IZQ
%token OP_DESP_DER
%token OP_MIEMBRO_PUNT

%token <valorString> CHAR
%token <valorString> STRING

%token SIZEOF
%token CLASE_ALM
%token CALIF_TIPO
%token STRUCT_UNION
%token ENUM

%union {
  int   valorEntero;
  double valorReal;
  char* valorString;
}

%%

input:   /* vacio */
       | input line
;

line:   '\n'
      | expresion '\n'
;

const:   NUM_ENTERO     {fprintf(yyout, "Numero Entero = %d\n", $<valorEntero>1);}
       | NUM_REAL       {fprintf(yyout, "Numero Real = %.2f\n", $<valorReal>1);}
       | CHAR           {fprintf(yyout, "Caracter = %s\n", $<valorString>1);}
       | const_enum
;

const_enum: ID {fprintf(yyout, "ID = %s\n", $<valorString>1);}
;

expresion:   exp_asignacion
           | expresion ',' exp_asignacion   {fprintf(yyout, "Se utiliza el \',\'\n");}
;

exp_asignacion:   exp_condicional
                | exp_unaria op_asignacion exp_asignacion
;

exp_condicional:   exp_OR_log
                 | exp_OR_log '?' expresion ':' exp_condicional {fprintf(yyout, "Se utiliza el \': ?\'\n");}
;

op_asignacion:   '='            {fprintf(yyout, "Se utiliza el \'=\'\n"  );}
               | ASIG_MULT      {fprintf(yyout, "Se utiliza el \'*=\'\n" );}
               | ASIG_DIV       {fprintf(yyout, "Se utiliza el \'/=\'\n" );}
               | ASIG_MOD       {fprintf(yyout, "Se utiliza el \'%=\'\n" );}
               | ASIG_SUMA      {fprintf(yyout, "Se utiliza el \'+=\'\n" );}
               | ASIG_RESTA     {fprintf(yyout, "Se utiliza el \'-=\'\n" );}
               | ASIG_DESP_IZQ  {fprintf(yyout, "Se utiliza el \'<<=\'\n");}
               | ASIG_DESP_DER  {fprintf(yyout, "Se utiliza el \'>>=\'\n");}
               | ASIG_AND_BIN   {fprintf(yyout, "Se utiliza el \'&=\'\n" );}
               | ASIG_XOR_BIN   {fprintf(yyout, "Se utiliza el \'^=\'\n" );}
               | ASIG_OR_BIN    {fprintf(yyout, "Se utiliza el \'|=\'\n" );}
;

exp_OR_log:   exp_AND_log
            | exp_OR_log OP_OR exp_AND_log   {fprintf(yyout, "Se utiliza el \'||\'\n");}
;

exp_AND_log:   exp_OR_in
             | exp_AND_log OP_AND exp_OR_in  {fprintf(yyout, "Se utiliza el \'&&\'\n");}
;

exp_OR_in:   exp_OR_ex
           | exp_OR_in '|' exp_OR_ex {fprintf(yyout, "Se utiliza el \'|\'\n");}
;

exp_OR_ex:   exp_AND
           | exp_OR_ex '^' exp_AND {fprintf(yyout, "Se utiliza el \'^\'\n");}
;

exp_AND:   exp_igualdad
         | exp_AND '&' exp_igualdad {fprintf(yyout, "Se utiliza el \'&\'\n");}
;

exp_igualdad:   exp_relacional
              | exp_igualdad OP_IGUALDAD    exp_relacional  {fprintf(yyout, "Se utiliza el \'==\'\n");}
              | exp_igualdad OP_DESIGUALDAD exp_relacional  {fprintf(yyout, "Se utiliza el \'!=\'\n");}
;

exp_relacional:   exp_desp
                | exp_relacional      '<'       exp_desp  {fprintf(yyout, "Se utiliza el \'<\'\n" );}
                | exp_relacional      '>'       exp_desp  {fprintf(yyout, "Se utiliza el \'>\'\n" );}
                | exp_relacional OP_MENOR_IGUAL exp_desp  {fprintf(yyout, "Se utiliza el \'<=\'\n");}
                | exp_relacional OP_MAYOR_IGUAL exp_desp  {fprintf(yyout, "Se utiliza el \'>=\'\n");}
;

exp_desp:   exp_aditiva
          | exp_desp OP_DESP_IZQ exp_aditiva  {fprintf(yyout, "Se utiliza el \'<<\'\n");}
          | exp_desp OP_DESP_DER exp_aditiva  {fprintf(yyout, "Se utiliza el \'>>\'\n");}
;

exp_aditiva:   exp_multip
             | exp_aditiva '+' exp_multip   {fprintf(yyout, "Se utiliza el \'+\'\n");}
             | exp_aditiva '-' exp_multip   {fprintf(yyout, "Se utiliza el \'-\'\n");}
;

exp_multip:   exp_conversion
            | exp_multip '*' exp_conversion   {fprintf(yyout, "Se utiliza el \'*\'\n");}
            | exp_multip '/' exp_conversion   {fprintf(yyout, "Se utiliza el \'/\'\n")}
            | exp_multip '%' exp_conversion   {fprintf(yyout, "Se utiliza el \'%\'\n");}
;

exp_conversion:   exp_unaria
                | '(' TIPO_DATO ')' exp_conversion exp_unaria {/*CAMBIAR POR nombre_tipo*/}
;

exp_unaria:   exp_sufijo
            | OP_INC exp_unaria           {fprintf(yyout, "Se utiliza el \'++\'\n");}
            | OP_DEC exp_unaria           {fprintf(yyout, "Se utiliza el \'--\'\n");}
            | op_unario exp_conversion
            | SIZEOF exp_unaria
            | SIZEOF '(' TIPO_DATO ')'  {/*CAMBIAR POR nombre_tipo*/}
;

op_unario:   '&'
           | '*' 
           | '+'
           | '-'
           | '~'
           | '!'
;

exp_sufijo:   exp_primaria
            | exp_sufijo '[' expresion ']'        {fprintf(yyout, "Se utiliza el \'[\' y el \']\'\n");                                    }
            | exp_sufijo '(' lista_argumentos ')' {fprintf(yyout, "Se utiliza el \'(\' y el \')\'\n");                                    }
            | exp_sufijo '.' ID                   {fprintf(yyout, "Se utiliza el \'.\'\n"); fprintf(yyout, "ID = %s\n", $<valorString>3); }
            | exp_sufijo OP_MIEMBRO_PUNT ID       {fprintf(yyout, "Se utiliza el \'->\'\n"); fprintf(yyout, "ID = %s\n", $<valorString>3);}
            | exp_sufijo OP_INC                   {fprintf(yyout, "Se utiliza el \'++\'\n");                                              }
            | exp_sufijo OP_DEC                   {fprintf(yyout, "Se utiliza el \'--\'\n");                                              }
;

lista_argumentos:   exp_asignacion
                  | lista_argumentos ',' exp_asignacion
;

exp_primaria:   const
              | STRING              {fprintf(yyout, "String = %s\n", $<valorString>1);  }
              | '(' expresion ')'   {fprintf(yyout, "Se utiliza el \'(\' y el \')\'\n");}               
;




%%

int yyerror (char *mensaje)  /* Funcion de error */
{
  printf ("Error: %s\n", mensaje);
}

void main(){ 

    yyin = fopen("Input.txt", "r");
    yyout = fopen("Salida.txt", "w");

    #ifdef BISON_DEBUG
       yydebug = 1;
    #endif
    
    yyparse();

    fclose(yyin);
    fclose(yyout);
}