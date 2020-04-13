#include <stdio.h>
#include <stdlib.h>

//Definición de nombres de los Estados del AFR
enum {Init, ReadedZero, ReadedOctal, ReadedX, ReadedHexa, ReadedDec, NoConst};
//Definición de nombres de las Condiciones de Cambios
enum{Zero, To1_7, To8_9, ToA_F, xX, Comma};

short ColumnPosition(char, FILE *); //Define la posición de la columna dependiendo la letra que lee
void showTypeOfConst(short, FILE *);    //Muestra en el archivo de salida los tipos de constantes leídas

int main()  //Función principal del programa
{   
    FILE *fileOfConstantsInput = fopen("Entrada.txt", "r"); //Archivo de Entrada con Constantes, para leer
    FILE *fileOfConstantsOutput = fopen("Salida.txt", "w+");    //Archivo de Salida con los Tipos, para escribir

    char letter;    //Variable donde se almacena cada caracter que se lee
    short eLectura = Init;  //Variable de Estado
    short anteriorLectura;  //Variable que guarda el estado anterior a "eLectura"
    char posColumn; //Variable donde se almacena la posición de columna

    //Tabla de Transición del AFR (7 Estados y 6 Condiciones de Cambio)
    unsigned short AFRConstantesEnteras[7][6] = {{ReadedZero, ReadedDec, ReadedDec, NoConst, NoConst, Init},
                                                 {ReadedOctal, ReadedOctal, NoConst, NoConst, ReadedX, Init},
                                                 {ReadedOctal, ReadedOctal, NoConst, NoConst, NoConst, Init},
                                                 {ReadedHexa, ReadedHexa, ReadedHexa, ReadedHexa, NoConst, Init},
                                                 {ReadedHexa, ReadedHexa, ReadedHexa, ReadedHexa, NoConst, Init},
                                                 {ReadedDec, ReadedDec, ReadedDec, NoConst, NoConst, Init},
                                                 {NoConst, NoConst, NoConst, NoConst, NoConst, Init} };

    if(fileOfConstantsInput != NULL)    //Chequea si se puede abrir el archivo de entrada
    {
        while(fread(&letter, sizeof(letter), 1, fileOfConstantsInput))  //Mientras haya caracteres para leer
        {   
            posColumn = ColumnPosition(letter, fileOfConstantsOutput);  //Asignación de la posición de columna
            anteriorLectura = eLectura; //Asignación del estado anterior
            eLectura = AFRConstantesEnteras[eLectura][posColumn];   //Indicación del estado actual

            if(posColumn == Comma)  //Si termina de leer, es decir, si lee una coma
                showTypeOfConst(anteriorLectura, fileOfConstantsOutput);   //Muestreo de los tipos de constantes
        }

        showTypeOfConst(eLectura, fileOfConstantsOutput);   //Muestreo del último tipo de constante
    }

    //Cierre de los archivos
    fclose(fileOfConstantsInput);
    fclose(fileOfConstantsOutput);

    return 0;
}

//En base a la letra, decide qué posición de columna tomar
//Además escribe los caracteres que llegan, salvo las comas
short ColumnPosition(char letter, FILE *fileOutput)
{
    short posColumn;

    if(letter == '0')
    {
        posColumn = Zero;
        fputc(letter, fileOutput);
    }
    else if(letter >= '1' && letter <= '7')
    {
        posColumn = To1_7;
        fputc(letter, fileOutput);
    }
        
    else if(letter == '8' || letter == '9')
    {
        posColumn = To8_9;
        fputc(letter, fileOutput);
    }
    else if((letter >= 'A' && letter <= 'F') || (letter >= 'a' && letter <= 'f'))
    {
        posColumn = ToA_F;
        fputc(letter, fileOutput);
    }
    else if(letter == 'x' || letter == 'X')
    {
        posColumn = xX;
        fputc(letter, fileOutput);
    }
    else if(letter == ',')
        posColumn = Comma;   
    else
        fputc(letter, fileOutput);
    
    return posColumn;
}

//Muestreo del tipo de constante leída
void showTypeOfConst(short status, FILE *fileOutput)
{
    switch (status)
        {
            case Init:
                fputs(" -> No es una Constante Entera\n", fileOutput);
                break;
            case ReadedZero:
                fputs(" -> Es una Constante Octal\n", fileOutput);
                break;
            case ReadedOctal:
                fputs(" -> Es una Constante Octal\n", fileOutput);
                break;
            case ReadedHexa:
                fputs(" -> Es una Constante Hexadecimal\n", fileOutput);
                break;
            case ReadedDec:
                fputs(" -> Es una Constante Decimal\n", fileOutput);
                break;
            case ReadedX:
                fputs(" -> No es una Constante Entera\n", fileOutput);
                break;
            case NoConst:
                fputs(" -> No es una Constante Entera\n", fileOutput);
                break;
        }
}