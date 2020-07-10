%option noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "Funciones.c"
%}

DECIMAL [0-9]
OCTAL [0-7]
HEXA {DECIMAL}|[a-fA-F]
LETRA [a-zA-Z]

TIPO_DATO char|int|float|double|long|short|signed|unsigned|void|enum|struct|typedef|union|const
ESTRUCTURA_CONTROL switch|case|break|default|continue|do|while|if|else|for|return|goto
OTROS volatile|extern|static|auto|register|sizeof

OPER_O_PUNT1 "++"|"--"|"."|"->"|"+"|"-"|"!"|"~"|"*"|"&"|"/"|"%"|"<<"|">>"|"<="|">="|"<"|">"|"=="|";"|"{"|"}"|":"
OPER_O_PUNT2 "!="|"^"|"|"|"&&"|"||"|"?"|"="|"+="|"-="|"*="|"/="|"%="|"<<="|">>="|"&="|"^="|"|="|","|"["|"]"|"("|")"

CONST_DECIMAL [1-9]{DECIMAL}*
CONST_OCTAL 0{OCTAL}*
CONST_HEXA 0[xX]{HEXA}+
CONST_REAL {DECIMAL}*"."{DECIMAL}*([eE](\+|\-)?{DECIMAL}+)?
CARACTER \'.\'
LITERAL_CADENA \".+\"
PALABRA_RESERVADA {TIPO_DATO}|{ESTRUCTURA_CONTROL}|{OTROS}
SALTO_LINEA \n
COMODIN .
IDENTIFICADOR ({LETRA}|_)({LETRA}|{DECIMAL}|_)*
OPER_O_PUNT {OPER_O_PUNT1}|{OPER_O_PUNT2}
COMENTARIO_LINEA "//".*
COMENTARIO_BLOQUE "/*"(.|\n)*"*/"
INCLUDE #include(" ")+(\".+\"|<.+>)

CONSTANTES {CONST_DECIMAL}|{CONST_OCTAL}|{CONST_HEXA}|{CONST_REAL}|{CARACTER}
TOKEN {PALABRA_RESERVADA}|{IDENTIFICADOR}|{OPER_OR_PUNT}|{CONSTANTES}|{LITERAL_CADENA}

%%
{INCLUDE}           {fprintf(yyout, "Encontre la directiva de precompilador: %s\n", yytext);}
{CONST_DECIMAL}     {insertarEnLista(&listaDeDecimales, yytext);}
{CONST_OCTAL}       {insertarEnLista(&listaDeOctales, yytext);}
{CONST_HEXA}        {insertarEnLista(&listaDeHexadecimales, yytext);}
{CONST_REAL}        {insertarEnLista(&listaDeReales, yytext);}
{CARACTER}          {fprintf(yyout, "Encontre el caracter: %s\n", yytext);}
{LITERAL_CADENA}    {insertarEnLista(&listaDeLiterales, yytext);}
{PALABRA_RESERVADA} {insertarEnLista(&listaDePalabrasReservadas, yytext);}
{IDENTIFICADOR}     {insertarOrdenado(&listaDeIdentificadores, yytext);}
{COMENTARIO_LINEA}  {fprintf(yyout, "Encontre el comentario de una linea: %s\n", yytext);}
{COMENTARIO_BLOQUE} {cantSaltosLinea += cantidadSaltosDeLinea(yytext);}
{SALTO_LINEA}       {cantSaltosLinea++;}
{COMODIN}           {/* fprintf(yyout, "Encontre el caracter no valido: %s\n", yytext); */}

%%
//CODIGO DE USUARIO

int main()
{
    yyin = fopen("Entrada.txt", "r");
    yyout = fopen("Salida.txt", "w");

    FILE* reporte = fopen("Reporte.txt", "w");

    yylex();

    fclose(yyin);
    fclose(yyout);

    printf("Cantidad de lineas: %d", cantSaltosLinea);
    generarReporte(reporte);
    
    fclose(reporte);
    
    return 0;
}
/* {INCLUDE}           {fprintf(yyout, "Encontre la directiva de precompilador: %s\n", yytext);}
{CONST_DECIMAL}     {fprintf(yyout, "Encontre la constante decimal: %s\n", yytext);}
{CONST_OCTAL}       {fprintf(yyout, "Encontre la constante octal: %s\n", yytext);}
{CONST_HEXA}        {fprintf(yyout, "Encontre la constante hexadecimal: %s\n", yytext);}
{CONST_REAL}        {fprintf(yyout, "Encontre la constante real: %s\n", yytext);}
{CARACTER}          {fprintf(yyout, "Encontre el caracter: %s\n", yytext);}
{LITERAL_CADENA}    {fprintf(yyout, "Encontre el literal cadena: %s\n", yytext);}
{PALABRA_RESERVADA} {fprintf(yyout, "Encontre la palabra reservada: %s\n", yytext);}
{IDENTIFICADOR}     {fprintf(yyout, "Encontre el identificador: %s\n", yytext);}
{OPER_O_PUNT}       {fprintf(yyout, "Encontre el caracter de puntuacion/operador: %s\n", yytext);}
{COMENTARIO_LINEA}  {fprintf(yyout, "Encontre el comentario de una linea: %s\n", yytext);}
{COMENTARIO_BLOQUE} {fprintf(yyout, "Encontre el bloque de comentario: %s\n", yytext);}
{SALTO_LINEA}       {}
{COMODIN}           {/* fprintf(yyout, "Encontre el caracter no valido: %s\n", yytext);} */