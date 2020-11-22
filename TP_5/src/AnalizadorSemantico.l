%option noyywrap

%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "AnalizadorSemantico.tab.h"
    #include "Tabla_Simbolos.h"

    
    char* cadenaErronea = NULL; 
    short errorFlag = 0; 
    Error* erroresLexicos = NULL;

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
            /*char* mensaje = strdup("Se encontro el error lexico: ");
            strcat(mensaje, cadenaErronea); */
            insertarError(&erroresLexicos, cadenaErronea);
            cadenaErronea = NULL;
        }
        errorFlag = 0;
    }
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

{CONST_DECIMAL}   { yylval.entero    = atoi(yytext); finalDeError(); return ENTERO; }
{CONST_OCTAL}     { yylval.entero    = strtoll(yytext, NULL, 8); finalDeError(); return ENTERO; }
{CONST_HEXA}      { yylval.entero    = strtoll(yytext, NULL, 16); finalDeError(); return ENTERO; } 
{CONST_REAL}      { yylval.real      = atof(yytext); finalDeError(); return REAL; }
{CONST_CHAR}      { yylval.caracter  = yytext[1]; finalDeError(); return CHAR; /* [!] Accedemos a la posicion 1 del yytext para obtener unicamente el caracter deseado y no las comillas simples */}
{LITERAL_CADENA}  { yylval.string    = strdup(yytext); finalDeError(); return STRING; }
{TIPO_DATO}       { yylval.string    = strdup(yytext); finalDeError(); return TIPO_DATO; }
{IDENTIFICADOR}   { yylval.string    = strdup(yytext); finalDeError(); return IDENTIFICADOR; }
{ESPACIOS}+       { finalDeError(); }
{CARACTER_SIMPLE} { finalDeError(); return yytext[0]; }
{COM_SIMPLE}      { finalDeError(); }  
{COM_BLOQUE}      { finalDeError(); }
{SALTO_LINEA}     { sumarLinea(); finalDeError(); } 
.                 { esError(yytext); }


%%