%option noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>
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
CONST_REAL {DECIMAL}*"."?{DECIMAL}*([eE]{DECIMAL}+)?
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

%%
{INCLUDE}           {printf("Encontre la directiva de precompilador: %s\n", yytext);}
{CONST_DECIMAL}     {printf("Encontre la constante decimal: %s\n", yytext);}
{CONST_OCTAL}       {printf("Encontre la constante octal: %s\n", yytext);}
{CONST_HEXA}        {printf("Encontre la constante hexadecimal: %s\n", yytext);}
{CONST_REAL}        {printf("Encontre la constante real: %s\n", yytext);}
{CARACTER}          {printf("Encontre el caracter: %s\n", yytext);}
{LITERAL_CADENA}    {printf("Encontre el literal cadena: %s\n", yytext);}
{PALABRA_RESERVADA} {printf("Encontre la palabra reservada: %s\n", yytext);}
{IDENTIFICADOR}     {printf("Encontre el identificador: %s\n", yytext);}
{OPER_O_PUNT}       {printf("Encontre el caracter de puntuacion/operador: %s\n", yytext);}
{COMENTARIO_LINEA}  {printf("Encontre el comentario de una linea: %s\n", yytext);}
{COMENTARIO_BLOQUE} {printf("Encontre el bloque de comentario: %s\n", yytext);}
{SALTO_LINEA}       {}
{COMODIN}           {printf("Encontre el caracter no valido: %s\n", yytext);}

%%
//CODIGO DE USUARIO

int main()
{
    /* yyin = fopen("Entrada.txt", "r");
    yyout = fopen("Salida.txt", "w"); */

    yylex();

    /* fclose(yyin);
    fclose(yyout); */

    return 0;
}
    
