#include <stdlib.h>
#include <stdio.h> 

#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H

enum {TIPO_VAR, TIPO_FUNC};
typedef struct Funcion{
    char*  tipoDatoParam;
    struct Funcion* sig;
} Funcion;

typedef struct Error{
    char*  mensajeError;
    short  numeroDeLinea;
    struct Error* sig;

} Error;
typedef union TipoValor {
    int      valEnt; 
    double   valReal;
    char     valChar;
    char*    valString;
    Funcion* func;
} TipoValor;

typedef struct Simbolo{
    char* nombre;
    char* tipoDato;
    int   tipoID;
    TipoValor valor;

    struct Simbolo* sig;
} Simbolo;

Simbolo*  crearSimbolo(char*, char*, int);
void      insertarSimbolo(Simbolo*);
Funcion*  crearParametro(char*);
void      insertarParametro(Funcion**, char*);
Simbolo*  devolverSimbolo(char*);
void      mostrarTabla(FILE*);
void      mostrarParametros(FILE*, Funcion*);
char*     toUpper(char*);
void      cambiarValor(Simbolo*, TipoValor);
unsigned  encontrarMasLargo();
char*     cantidadDeEspacios(unsigned);
TipoValor limpiarUnion();
void      sumarLinea();
unsigned  cantidadDeParametros(Funcion*);
void      verificarParametros(Simbolo*, Funcion*, FILE*);
void      insertarError(Error**, char*);
void      mostrarError(Error*, FILE*);
void      generarReporte(FILE*);

extern Simbolo* tablaSimbolos;
extern unsigned cantidadDeLineas; // [❗] Especificas que estas variables van a poder ser utilizadas tanto en Tabla_Simbolos.c como tambien en un archivo externo 
extern Error* erroresLexicos;

#endif