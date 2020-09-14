%option noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "AnalizadorSintactico.tab.h"
%}

CARACT_SIMPLES "+"|"-"|"*"|"/"|"^"|"("|")"|","|";"|"\n"|"="

DECIMAL        [0-9]
OCTAL          [0-7]
HEXA           [a-fA-F0-9]
LETRA          [a-zA-Z]

CONST_DECIMAL  [1-9]{DECIMAL}*
CONST_OCTAL    0{OCTAL}*
CONST_HEXA     0[xX]{HEXA}+
CONST_REAL     {DECIMAL}*"."{DECIMAL}*([eE](\+|\-)?{DECIMAL}+)?

ESPACIOS       " "|"\t"
COMODIN        .

%%

{CONST_DECIMAL}   {yylval.valorEntero = atoi(yytext); return NUMENT;}
{CONST_HEXA}      {yylval.valorEntero = strtoll(yytext, NULL, 16); return NUMENT;}
{CONST_OCTAL}     {yylval.valorEntero = strtoll(yytext, NULL, 8); return NUMENT;}
{CONST_REAL}      {yylval.valorReal   = atof(yytext); return NUMREAL;}
{CARACT_SIMPLES}  {return yytext[0];}
{ESPACIOS}+       {}
{COMODIN}         {}

%%