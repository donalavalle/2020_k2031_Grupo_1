#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

enum {Init, ReadedZero, ReadedOctal, ReadedX, ReadedHexa, ReadedDec, NoConst};

short AFRLecturaConstEnt(char, short, FILE *);

int main()
{
    FILE *fileOfConstantsInput = fopen("Entrada.txt", "r");
    FILE *fileOfConstantsOutput = fopen("Salida.txt", "w+");

    if(fileOfConstantsInput != NULL)
    {
        short eLectura = Init;
        char letter;

        while(fread(&letter, sizeof(letter), 1, fileOfConstantsInput))
            eLectura = AFRLecturaConstEnt(letter, eLectura, fileOfConstantsOutput);
        switch (eLectura)
        {
            case ReadedDec:
                fputs(" -> Es una Constante Decimal", fileOfConstantsOutput);
            break;

            case ReadedHexa:
                fputs(" -> Es una Constante Hexadecimal", fileOfConstantsOutput);
            break;

             case ReadedOctal:
                fputs(" -> Es una Constante Octal", fileOfConstantsOutput);
            break;

            case NoConst:
                fputs(" -> No es una Constante Entera", fileOfConstantsOutput);
            break;
        }
    }
    fclose(fileOfConstantsInput);
    fclose(fileOfConstantsOutput);
    return 0;
}

short AFRLecturaConstEnt(char letter, short eLectura, FILE *fileOutput)
{
    switch (eLectura)
    {
        default:
        case Init:
            if(letter == '0')
            {   
                eLectura = ReadedZero;
                fwrite(&letter, sizeof(letter), 1, fileOutput);
            }
            else if(letter >= '1' &&  letter <= '9')
            {
                eLectura = ReadedDec;
                fwrite(&letter, sizeof(letter), 1, fileOutput);
            }    
            else if(letter == ',')
                eLectura = Init;
            else
            {
                eLectura = NoConst;
                fwrite(&letter, sizeof(letter), 1, fileOutput);
            }
                
        break;

        case ReadedZero:
            if(letter >= '0' && letter <= '7')
            {
                eLectura = ReadedOctal;
                fwrite(&letter, sizeof(letter), 1, fileOutput);
            }      
            else if(toupper(letter) == 'X')
                {
                eLectura = ReadedX;
                fwrite(&letter, sizeof(letter), 1, fileOutput);
                } 
            else if(letter == ',')
            {
                eLectura = Init;
                fputs(" -> Es una Constante Octal \n", fileOutput);
            }
            else
            {
                eLectura = NoConst;
                fwrite(&letter, sizeof(letter), 1, fileOutput);
            }     
        break;

        case ReadedOctal:
            if(letter >= '0' && letter <= '7')
            {
                eLectura = ReadedOctal;
                fwrite(&letter, sizeof(letter), 1, fileOutput);
            }     
            else if(letter == ',')
            {
                eLectura = Init;
                fputs(" -> Es una Constante Octal \n", fileOutput);
            }
            else
            {
                eLectura = NoConst;
                fwrite(&letter, sizeof(letter), 1, fileOutput);
            }    
        break;

        case ReadedX: 
            letter = toupper(letter);
            if((letter >= '0' && letter <= '9') || (letter >= 'A' && letter <= 'F'))
            {
                eLectura = ReadedHexa;
                fwrite(&letter, sizeof(letter), 1, fileOutput);
            }
            else if(letter == ',')
            {
                eLectura = Init;
                fputs(" -> No es una Constante Entera \n", fileOutput);
            }
            else
            {
                eLectura = NoConst;
                fwrite(&letter, sizeof(letter), 1, fileOutput);
            }    
        break;

        case ReadedHexa:
            letter = toupper(letter);
            if(letter >= '0' & letter <= '9')
            {
                eLectura = ReadedHexa;
                fwrite(&letter, sizeof(letter), 1, fileOutput);
            }
            else if(letter >= 'A' && letter <= 'F')
            {
                eLectura = ReadedHexa;
                fwrite(&letter, sizeof(letter), 1, fileOutput);
            }
                
            else if(letter == ',')
            {
                eLectura = Init;
                fputs(" -> Es una Constante Hexadecimal \n", fileOutput);
            }
            else
            {
                eLectura = NoConst;
                fwrite(&letter, sizeof(letter), 1, fileOutput);
            }         
        break;

        case ReadedDec:
            if(letter >= '0' && letter <= '9')
            {
                eLectura = ReadedDec;
                fwrite(&letter, sizeof(letter), 1, fileOutput);
            } 
            else if(letter == ',')
                {
                    eLectura = Init;
                    fputs(" -> Es una Constante Decimal \n", fileOutput);
                }
            else
            {
                eLectura = NoConst;
                fwrite(&letter, sizeof(letter), 1, fileOutput);
            }     
        break;

        case NoConst:
            if(letter == ',')
            {
                eLectura = Init;
                fputs(" -> No es una Constante Entera \n", fileOutput);
            }
            else
                fwrite(&letter, sizeof(letter), 1, fileOutput);      
        break;
    }
    return eLectura;
}