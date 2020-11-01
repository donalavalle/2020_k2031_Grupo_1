#include <stdlib.h>
#include <stdio.h>

#ifndef ANALIZADORSEMANTICO_H
#define ANALIZADORSEMANTICO_H

enum {TIPO_VAR, TIPO_FUNC};

typedef struct Funcion{
    char*  tipoDatoParam;
    struct Funcion* sig;
} Funcion;

typedef struct Simbolo{
    char* nombre;
    char* tipoDato;
    int   tipoID;
    union{
        int      valEnt; 
        double   valReal;
        char*    valChar;
        Funcion* func;
    } valor;

    struct Simbolo* sig;  
} Simbolo;

Simbolo* crearSimbolo(char*, char*, int);
void     insertarSimbolo(char*, char*, int);
Funcion* crearParametro(char*);
void     insertarParametro(Funcion**, char*);
Simbolo* devolverSimbolo(char*);
void     mostrarTabla(FILE*);
void     mostrarParametros(FILE*, Funcion*);
char*    toUpper(char*);

extern Simbolo* tablaSimbolos;

#endif