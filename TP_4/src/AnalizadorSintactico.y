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

%token <valorEntero> NUMENT
%token <valorReal> NUMREAL
%token <string> TIPO_DATO
%token <string> ID
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
%token <string> CONST_CHAR
%token <string> STRING

%token SIZEOF
%token CLASE_ALM
%token CALIF_TIPO
%token STRUCT_UNION
%token ENUM

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
      | expresion '\n' 
;


constante:   NUMENT     {printf("Numero Entero = %d\n", $<string>1);}
           | NUMREAL    {printf("Numero Real = %f\n", $<string>1);}
           | CONST_CHAR {printf("Caracter = %s\n", $<string>1);}
           | constante_enumeracion
;

constante_enumeracion: ID {printf("ID = %s\n", $<string>1);}
;

expresion:   exp_asignacion
           | expresion ',' exp_asignacion
;

exp_asignacion:   exp_condicional
                | exp_unaria op_asignacion exp_asignacion
;
 
exp_condicional:   exp_OR_logico
                 | exp_OR_logico '?' expresion ':' exp_condicional
;

op_asignacion:   '='
               | ASIG_MULT
               | ASIG_DIV
               | ASIG_MOD
               | ASIG_SUMA
               | ASIG_RESTA
               | ASIG_DESP_IZQ
               | ASIG_DESP_DER
               | ASIG_AND_BIN
               | ASIG_XOR_BIN
               | ASIG_OR_BIN
;

exp_OR_logico:   exp_AND_logico
               | exp_OR_logico OP_OR exp_AND_logico
;

exp_AND_logico:   exp_OR_inclusivo
                | exp_AND_logico OP_AND exp_OR_inclusivo
;

exp_OR_inclusivo:   exp_OR_excluyente
                  | exp_OR_inclusivo '|' exp_OR_excluyente
;

exp_OR_excluyente:   exp_AND
                   | exp_OR_excluyente '^' exp_AND
;

exp_AND:   exp_igualdad
         | exp_AND '&' exp_igualdad
;

exp_igualdad:   exp_relacional
              | exp_igualdad OP_IGUALDAD exp_relacional
              | exp_igualdad OP_DESIGUALDAD exp_relacional
;

exp_relacional:   exp_corrimiento
                | exp_relacional '<' exp_corrimiento
                | exp_relacional '>' exp_corrimiento
                | exp_relacional OP_MENOR_IGUAL exp_corrimiento
                | exp_relacional OP_MAYOR_IGUAL exp_corrimiento
;

exp_corrimiento:   exp_aditiva
                 | exp_corrimiento OP_DESP_IZQ exp_aditiva
                 | exp_corrimiento OP_DESP_DER exp_aditiva
;

exp_aditiva:   exp_multip
             | exp_aditiva '+' exp_multip
             | exp_aditiva '-' exp_multip
;

exp_multip:   exp_conversion
            | exp_multip '*' exp_conversion
            | exp_multip '/' exp_conversion
            | exp_multip '%' exp_conversion
;

exp_conversion:   exp_unaria
                | '(' nombre_de_tipo ')' exp_conversion exp_unaria
;

exp_unaria:   exp_sufijo
            | OP_INC exp_unaria
            | OP_DEC exp_unaria
            | op_unario exp_conversion
            | SIZEOF exp_unaria
            | SIZEOF '(' nombre_de_tipo ')'
;

op_unario:   '&'
           | '*' 
           | '+'
           | '-'
           | '~'
           | '!'
;

exp_sufijo:   exp_primaria
            | exp_sufijo '[' expresion ']'
            | exp_sufijo '(' lista_argumentos ')'
            | exp_sufijo '.' ID
            | exp_sufijo OP_MIEMBRO_PUNT ID
            | exp_sufijo OP_INC
            | exp_sufijo OP_DEC
;

lista_argumentos:   exp_asignacion
                  | lista_argumentos ',' exp_asignacion
;

exp_primaria:   ID 
              | constante
              | STRING
              | '(' expresion ')'
;

nombre_de_tipo:   lista_calificadores declarador_opc_abs
;

declarador_opc_abs:   /* Vacío */
                    | declarador_abs
;

declarador_abs:   puntero declarador_opc_abs_directo
                | declarador_abs_directo
;

declarador_opc_abs_directo:   /* Vacío */
                            | declarador_abs_directo
;

exp_constante: exp_condicional
;

exp_opc_constante:   /* Vacío*/
                   | exp_constante
;

deriv_dec_abs_directo:   '[' exp_opc_constante ']'
                       | '(' lista_opc_tipo_parametros ')'
;

declarador_abs_directo:   '(' declarador_abs ')'
                        | declarador_opc_abs_directo deriv_dec_abs_directo
;

declaracion_parametro:   especificadores_declaracion decla
                       | especificadores_declaracion declarador_opc_abs
;

lista_parametros:   declaracion_parametro lista_opc_parametros
;

lista_opc_parametros:   /* Vacío* /
                      | ',' lista_parametros
;

lista_tipo_parametros: lista_parametros lista_opc_tipo_parametros_coma
;

lista_opc_tipo_parametros_coma:   /* Vacío */
                                | ',' lista_tipo_parametros
;

lista_opc_tipo_parametros:   /* Vacío* /
                           | lista_tipo_parametros
;

declaracion:   especificadores_declaracion lista_opc_declaradores
;

lista_opc_declaradores:   /* Vacío */
                        | lista_declaradores
;

especificadores_declaracion:   CLASE_ALM especificadores_opc_declaracion
                             | especificador_tipo especificadores_opc_declaracion
                             | CALIF_TIPO especificadores_opc_declaracion
;

especificadores_opc_declaracion:   /* Vacío */
                                 | especificadores_declaracion
;

lista_declaradores:   declarador lista_opc_declaradores_coma
;

lista_opc_declaradores_coma:   /* Vacío */
                             | ',' lista_declaradores
;

declarador:   decla inicializador_opc
;

inicializador_opc:   /* Vacío */
                   | '=' inicializador
;

inicializador:   exp_asignacion
               | '{' lista_inicializadores '}'
;

lista_inicializadores:   inicializador lista_opc_inicializadores_coma
;

lista_opc_inicializadores_coma:   /* Vacío */
                                | ',' lista_inicializadores
;

especificador_tipo:   TIPO_DATO
                    | especificador_struct_union
                    | especificador_enum
                    | nombre_typedef
;

especificador_struct_union:   STRUCT_UNION struct_union_opc  
;

struct_union_opc:  '{' lista_declaraciones_struct '}'
                  | ID lista_opc_declaraciones_struct_llave
;

lista_opc_declaraciones_struct_llave:   /* Vacío */
                                     | '{' lista_declaraciones_struct '}'
;

lista_declaraciones_struct: declaracion_struct lista_opc_declaraciones_struct
;

lista_opc_declaraciones_struct:   /* Vacío */
                                | ';' lista_declaraciones_struct
;

declaracion_struct: lista_calificadores declaradores_struct 
;

lista_calificadores:   especificador_tipo lista_opc_calificadores 
                     | CALIF_TIPO lista_opc_calificadores
;

lista_opc_calificadores:   /* Vacío */
                         | lista_calificadores
;

declaradores_struct: decla_struct declaradores_opc_struct_coma
;

declaradores_opc_struct_coma:   /* Vacío */
                              | ',' declaradores_struct
;

decla_struct:   decla exp_constante_opc_dosPuntos
              | ':' exp_constante
;

exp_constante_opc_dosPuntos:   /* Vacío */
                             | ':' exp_constante
;

decla: puntero_opc declarador_directo
;

puntero: '*' lista_calificadores_tipos_opc puntero_opc
;

lista_calificadores_tipos_opc:   /* Vacío */
                               | lista_calificadores_tipos
;

puntero_opc:   /* Vacío */
             | puntero
;

lista_calificadores_tipos: CALIF_TIPO lista_calificadores_tipos_opc
;

declarador_directo:   ID
                    | '(' decla ')'
                    | declarador_directo '[' exp_opc_constante ']'
                    | declarador_directo '(' lista_tipo_parametros ')'
;


listaDeIdentificadores:   ID
                        | ID ',' listaDeIdentificadores
;

especificador_enum:   ENUM ID '{' lista_enumeradores '}'
                    | ENUM ID
                    | ENUM '{' lista_enumeradores '}'
;

lista_enumeradores:   enumerador
                    | enumerador ',' lista_enumeradores
;

enumerador:   constante_enumeracion
            | constante_enumeracion '=' exp_constante
;

nombre_typedef: ID
;

nombre_de_tipo:   lista_calificadores declarador_opc_abs
;

%%

int yyerror (char *mensaje)  /* Funcion de error */
{
  printf ("Error: %s\n", mensaje);
}

void main(){ 

    /* yyin = fopen("Input.txt", "r");
    yyout = fopen("Salida.txt", "w"); */

    #ifdef BISON_DEBUG
       yydebug = 1;
    #endif
    
    yyparse();

    /* fclose(yyin);
    fclose(yyout); */
}