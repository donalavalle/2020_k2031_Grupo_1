%option noyywrap

%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "AnalizadorSemantico.tab.h"
    #include "Tabla_Simbolos.h"

    
    char* cadenaErronea = NULL;    // [❗] Variable que almacena la cadena erronea  
    short errorFlag = 0;           // [❗] Flag que permite o no ingresar la cadena de errores lexicos
    Error* erroresLexicos = NULL;  // [❗] Lista de errrores lexicos.

    void esError(char* charErroneo){  // [❗] Almacena el caracter no reconocido en la cadena erronea.
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

    void finalDeError(){  // [❗] Dependiendo del flagError, inserta o no la cadena erronea en la lista de errores LEXICOS. 
        if (errorFlag) // [❗] Pregunta si se reconoció un error previamente
        {
            /*char* mensaje = strdup("Se encontro el error lexico: ");
            strcat(mensaje, cadenaErronea);*/
            insertarError(&erroresLexicos, cadenaErronea);
            //insertarError(&erroresLexicos, mensaje);
            cadenaErronea = NULL; // [❗] Se reinicia la variable para reutilizarla.
        }
        errorFlag = 0; // [❗] Reinicia el flag.
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

{CONST_DECIMAL}   { finalDeError(); yylval.entero    = atoi(yytext); return ENTERO; }
{CONST_OCTAL}     { finalDeError(); yylval.entero    = strtoll(yytext, NULL, 8); return ENTERO; }
{CONST_HEXA}      { finalDeError(); yylval.entero    = strtoll(yytext, NULL, 16); return ENTERO; } 
{CONST_REAL}      { finalDeError(); yylval.real      = atof(yytext); return REAL; }
{CONST_CHAR}      { finalDeError(); yylval.caracter  = yytext[1]; return CHAR; /* [❗] Accedemos a la posicion 1 del yytext para obtener unicamente el caracter deseado y no las comillas simples */}
{LITERAL_CADENA}  { finalDeError(); yylval.string    = strdup(yytext); return STRING; }
{TIPO_DATO}       { finalDeError(); yylval.string    = strdup(yytext); return TIPO_DATO; }
{IDENTIFICADOR}   { finalDeError(); yylval.string    = strdup(yytext); return IDENTIFICADOR; }
{ESPACIOS}+       { finalDeError(); }
{CARACTER_SIMPLE} { finalDeError(); return yytext[0]; }
{COM_SIMPLE}      { finalDeError(); }  
{COM_BLOQUE}      { finalDeError(); }
{SALTO_LINEA}     { finalDeError(); sumarLinea(); } 
<<EOF>>           { finalDeError(); yyterminate(); /*[!] Regla que sirve para detectar el Fin de Archivo*/} 
.                 { esError(yytext); }

%%