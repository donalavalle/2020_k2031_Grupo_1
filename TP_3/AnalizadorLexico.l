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
COMENTARIO_BLOQUE "/*"([^*]|\*+[^/])*\*+\/
INCLUDE #include(" ")+(\".+\"|<.+>)
DEFINE #define(" ")+[^" "|"\n"]+(" ")*.*
DIRECTIVA {INCLUDE}|{DEFINE}

%%
{DIRECTIVA}         {fprintf(yyout, "Encontre la directiva de precompilador: %s\n", yytext); finalDeError();}
{CONST_DECIMAL}     {insertarEnLista(&listaDeDecimales, yytext); finalDeError();}
{CONST_OCTAL}       {insertarEnLista(&listaDeOctales, yytext); finalDeError();}
{CONST_HEXA}        {insertarEnLista(&listaDeHexadecimales, yytext); finalDeError();}
{CONST_REAL}        {insertarEnLista(&listaDeReales, yytext); finalDeError();}
{CARACTER}          {insertarEnLista(&listaDeCaracteres, yytext); finalDeError();}
{OPER_O_PUNT}       {insertarOrdenado(&listaDeOperYPunt, yytext); finalDeError();}
{LITERAL_CADENA}    {insertarEnLista(&listaDeLiterales, yytext); finalDeError();}
{PALABRA_RESERVADA} {insertarEnLista(&listaDePalabrasReservadas, yytext); finalDeError();}
{IDENTIFICADOR}     {insertarOrdenado(&listaDeIdentificadores, yytext); finalDeError();}
{COMENTARIO_LINEA}  {insertarEnLista(&listaDeComentariosDeLinea, yytext); finalDeError();}
{COMENTARIO_BLOQUE} {insertarEnLista(&listaDeComentariosDeBloque, yytext); cantSaltosLinea += cantidadSaltosDeLinea(yytext); finalDeError();}
{SALTO_LINEA}       {cantSaltosLinea++; finalDeError();}
{COMODIN}           {esError(yytext);}

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