%option noyywrap

%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "AnalizadorSemantico.tab.h"
    #include "Tabla_Simbolos.h"
%}

DECIMAL         [0-9]
LETRA           [a-zA-Z]

CONST_DECIMAL    [1-9]{DECIMAL}*
CONST_OCTAL      0[0-7]*
CONST_HEXA       0[xX][a-fA-F0-9]+
CONST_CHAR       \'.\'
CONST_REAL       {DECIMAL}+\.{DECIMAL}+

LITERAL_CADENA   \".+\"
TIPO_DATO        "int"|"char"|"float"
IDENTIFICADOR    ({LETRA}|_)({LETRA}|_|{DECIMAL})*
ESPACIOS         " "|"\t"
CARACTER_SIMPLE  "="|";"|","|"*"|"("|")"|"+"
COM_SIMPLE       "//".*
COM_BLOQUE       "/*"([^*]|\*+[^/])*\*+\/
SALTO_LINEA      "\n" 

%%

{CONST_DECIMAL}   { yylval.entero    = atoi(yytext); return ENTERO; }
{CONST_OCTAL}     { yylval.entero    = strtoll(yytext, NULL, 8); return ENTERO; }
{CONST_HEXA}      { yylval.entero    = strtoll(yytext, NULL, 16); return ENTERO; } 
{CONST_REAL}      { yylval.real      = atof(yytext); return REAL; }
{CONST_CHAR}      { yylval.caracter  = yytext[1]; return CHAR; /* [!] Accedemos a la posicion 1 del yytext para obtener unicamente el caracter deseado y no las comillas simples */}
{LITERAL_CADENA}  { yylval.string    = strdup(yytext); return STRING; }
{TIPO_DATO}       { yylval.string    = strdup(yytext); return TIPO_DATO; }
{IDENTIFICADOR}   { yylval.string    = strdup(yytext); return IDENTIFICADOR; }
{ESPACIOS}+       { }
{CARACTER_SIMPLE} { return yytext[0]; }
{COM_SIMPLE}      { }
{COM_BLOQUE}      { }
{SALTO_LINEA}     {sumarLinea();} 


%%