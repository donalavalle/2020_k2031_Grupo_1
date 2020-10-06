%option noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "AnalizadorSintactico.tab.h"

    char* cadenaErronea = NULL;
    unsigned errorFlag = 0;
    unsigned cantLineas = 1;

    int printError(char*, int);

    void esError(char* charErroneo){
        if(cadenaErronea == NULL)
            cadenaErronea = strdup(charErroneo);
        else
        {
            char * ptr = malloc(strlen(charErroneo) + strlen(cadenaErronea) + 1);
            strcpy(ptr, cadenaErronea);
            strcat(ptr, charErroneo);
            cadenaErronea = strdup(ptr);
        }
        errorFlag = 1;
    } 

    void finalDeError(){
        if (errorFlag)
        {
            printError(cadenaErronea, cantLineas);
            cadenaErronea = NULL;
        }
        errorFlag = 0;
    }

    int cantidadSaltosDeLinea(char* data){
        int cant = 0;
        int i = 0;
        while(data[i] != '\0')
        {
            if(data[i] == '\n')
                cant++;
            i++;
        }

        return cant;
    }
%}

CARACT_SIMPLES "+"|"-"|"*"|"/"|"^"|"("|")"|","|";"|"="|"<"|">"|"%"|"&"|"|"|"~"|"!"|"?"|":"|"["|"]"|"{"|"}"|"."

DECIMAL        [0-9]
OCTAL          [0-7]
HEXA           [a-fA-F0-9]
LETRA          [a-zA-Z]

CONST_DECIMAL  [1-9]{DECIMAL}*
CONST_OCTAL    0{OCTAL}*
CONST_HEXA     0[xX]{HEXA}+
CONST_REAL     {DECIMAL}+"."{DECIMAL}+([eE](\+|\-)?{DECIMAL}+)?
CONST_CHAR     \'.\'
LITERAL_CADENA \".+\"

TIPOS_DATO    "void"|"char"|"short"|"int"|"long"|"float"|"double"|"signed"|"unsigned"
CLASE_ALM     "typedef"|"static"|"auto"|"register"|"extern"
CALIF_TIPO    "const"|"volatile"
STRUCT_UNION  "struct"|"union"
CONTINUE_BREAK "continue"|"break"

IDENTIFICADOR ({LETRA}|_)({LETRA}|{DECIMAL}|_)*

COMENTARIO_LINEA "//".*
COMENTARIO_BLOQUE "/*"([^*]|\*+[^/])*\*+\/

INCLUDE #include(" ")+(\".+\"|<.+>)
DEFINE #define(" ")+[^" "|"\n"]+(" ")*.*

ESPACIOS       " "|"\t"
COMODIN        .

%%

{CONST_DECIMAL}    {yylval.valorEntero = atoi(yytext); finalDeError(); return NUM_ENTERO;}
{CONST_HEXA}       {yylval.valorEntero = strtoll(yytext, NULL, 16); finalDeError(); return NUM_ENTERO;}
{CONST_OCTAL}      {yylval.valorEntero = strtoll(yytext, NULL, 8); finalDeError(); return NUM_ENTERO;}
{CONST_REAL}       {yylval.valorReal   = atof(yytext); finalDeError(); return NUM_REAL;}
{CARACT_SIMPLES}   {finalDeError(); return yytext[0];}
{CONTINUE_BREAK}   {finalDeError(); return CONTINUE_BREAK;}
{INCLUDE}          {finalDeError();}
{DEFINE}           {finalDeError();}
"if"               {yylval.valorString = strdup(yytext); finalDeError(); return IF;}
"else"             {yylval.valorString = strdup(yytext); finalDeError(); return ELSE;}
"switch"           {yylval.valorString = strdup(yytext); finalDeError(); return SWITCH;}
"while"            {yylval.valorString = strdup(yytext); finalDeError(); return WHILE;}
"do"               {yylval.valorString = strdup(yytext); finalDeError(); return DO;}
"for"              {yylval.valorString = strdup(yytext); finalDeError(); return FOR;}
"case"             {yylval.valorString = strdup(yytext); finalDeError(); return CASE;}
"default"          {yylval.valorString = strdup(yytext); finalDeError(); return DEFAULT;}
"return"           {yylval.valorString = strdup(yytext); finalDeError(); return RETURN;}
"goto"             {yylval.valorString = strdup(yytext); finalDeError(); return GOTO;}
{TIPOS_DATO}       {yylval.valorString = strdup(yytext); finalDeError(); return TIPO_DATO;}
{CLASE_ALM}        {yylval.valorString = strdup(yytext); finalDeError(); return CLASE_ALM;}
{CALIF_TIPO}       {finalDeError(); return CALIF_TIPO;}
{STRUCT_UNION}     {finalDeError(); return STRUCT_UNION;}
"sizeof"           {finalDeError(); return SIZEOF;}
"enum"             {finalDeError(); return ENUM;}
{IDENTIFICADOR}    {yylval.valorString = strdup(yytext); finalDeError(); return ID;}
{COMENTARIO_LINEA} {finalDeError();}
{COMENTARIO_BLOQUE} {cantLineas += cantidadSaltosDeLinea(yytext); finalDeError();}
"\n"               {cantLineas++;}
{ESPACIOS}+        {finalDeError();}
{COMODIN}          {esError(yytext);}


{CONST_CHAR}       {yylval.valorString = strdup(yytext); finalDeError(); return CHAR;}
{LITERAL_CADENA}   {yylval.valorString = strdup(yytext); finalDeError(); return STRING;}

"*="               {finalDeError(); return ASIG_MULT;}
"/="               {finalDeError(); return ASIG_DIV;}
"%="               {finalDeError(); return ASIG_MOD;}
"+="               {finalDeError(); return ASIG_SUMA;}
"-="               {finalDeError(); return ASIG_RESTA;}
"<<="              {finalDeError(); return ASIG_DESP_IZQ;}
">>="              {finalDeError(); return ASIG_DESP_DER;}
"&="               {finalDeError(); return ASIG_AND_BIN;}
"^="               {finalDeError(); return ASIG_XOR_BIN;}
"|="               {finalDeError(); return ASIG_OR_BIN;}
"++"               {finalDeError(); return OP_INC;}
"--"               {finalDeError(); return OP_DEC;}
"=="               {finalDeError(); return OP_IGUALDAD;}
"!="               {finalDeError(); return OP_DESIGUALDAD;}
"&&"               {finalDeError(); return OP_AND;}
"||"               {finalDeError(); return OP_OR;}
"<="               {finalDeError(); return OP_MENOR_IGUAL;}
">="               {finalDeError(); return OP_MAYOR_IGUAL;}
"<<"               {finalDeError(); return OP_DESP_IZQ;}
">>"               {finalDeError(); return OP_DESP_DER;}
"->"               {finalDeError(); return OP_MIEMBRO_PUNT;}
%%