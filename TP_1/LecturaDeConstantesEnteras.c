#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

enum {Init, ReadedZero, ReadedOctal, ReadedX, ReadedHexa, ReadedDec, NoConst};

short AFRLecturaConstEnt(char, short);

int main()
{
    short eLectura = Init;
    char word[10] = "0156,";
    unsigned i = 0;

    while(word[i] != '\0')
    {
        printf("%d. Letter: %c\n", i, word[i]);
        eLectura = AFRLecturaConstEnt(word[i], eLectura);
        i++;
    }


    return 0;
}

short AFRLecturaConstEnt(char letter, short eLectura)
{

    switch (eLectura)
    {
        default:
        case Init:
            if(letter == '0')
                eLectura = ReadedZero;
            else if(letter == '1' || letter == '2' || letter == '3' || letter == '4' || letter == '5')
                eLectura = ReadedDec;
            else if(letter == '6' || letter == '7' || letter == '8' || letter == '9')
                eLectura = ReadedDec;
            else if(letter == ',')
                eLectura = Init;
            else
                eLectura = NoConst;
        break;

        case ReadedZero:
            if(letter == '0' || letter == '1' || letter == '2' || letter == '3')
                eLectura = ReadedOctal;
            else if(letter == '4' || letter == '5' || letter == '6' || letter == '7')
                eLectura = ReadedOctal;
            else if(toupper(letter) == 'X')
                eLectura = ReadedX;
            else if(letter == ',')
                eLectura = Init;
            else
                eLectura = NoConst;
        break;

        case ReadedOctal:
            if(letter == '0' || letter == '1' || letter == '2' || letter == '3')
                eLectura = ReadedOctal;
            else if(letter == '4' || letter == '5' || letter == '6' || letter == '7')
                eLectura = ReadedOctal;
            else if(letter == ',')
            {
                eLectura = Init;
                puts("Es constante octal");
            }

            else
                eLectura = NoConst;
        break;

        case ReadedX:
            letter = toupper(letter);
            if(letter == '0' || letter == '1' || letter == '2' || letter == '3' || letter == '4')
                eLectura = ReadedHexa;
            else if(letter == '5' || letter == '6' || letter == '7' || letter == '8' || letter == '9')
                eLectura = ReadedHexa;
            else if(letter == 'A' || letter == 'B' || letter == 'C')
                eLectura = ReadedHexa;
            else if(letter == 'D' || letter == 'E' || letter == 'F')
                eLectura = ReadedHexa;
            else
                eLectura = NoConst;
        break;

        case ReadedHexa:
            letter = toupper(letter);
            if(letter == '0' || letter == '1' || letter == '2' || letter == '3' || letter == '4')
                eLectura = ReadedHexa;
            else if(letter == '5' || letter == '6' || letter == '7' || letter == '8' || letter == '9')
                eLectura = ReadedHexa;
            else if(letter == 'A' || letter == 'B' || letter == 'C')
                eLectura = ReadedHexa;
            else if(letter == 'D' || letter == 'E' || letter == 'F')
                eLectura = ReadedHexa;
            else if(letter == ',')
            {
                eLectura = Init;
                puts("Es constante hexadecimal");
            }
            else
                eLectura = NoConst;
        break;

        case ReadedDec:
            if(letter == '0' || letter == '1' || letter == '2' || letter == '3' || letter == '4')
                eLectura = ReadedDec;
            else if(letter == '5' || letter == '6' || letter == '7' || letter == '8' || letter == '9')
                eLectura = ReadedDec;
            else if(letter == ',')
                {
                    eLectura = Init;
                    puts("Es constante decimal");
                }
            else
                eLectura = NoConst;
        break;

        case NoConst:
            puts("No es una constante entera.");
            if(letter == ',')
                eLectura = Init;
        break;
    }

    return eLectura;
}
