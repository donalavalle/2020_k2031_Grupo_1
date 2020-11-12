#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#include "Tabla_Simbolos.h"

Simbolo* crearSimbolo(char* tipoDato, char* nombreID, int tipoID){
    Simbolo* nuevoNodo = (Simbolo*) malloc (sizeof(Simbolo));

    nuevoNodo -> nombre   = strdup(nombreID);
    nuevoNodo -> tipoDato = strdup(tipoDato);
    nuevoNodo -> tipoID   = tipoID;

    switch(tipoID){
        default:
            break;
        case TIPO_VAR:
                if(! strcmp(tipoDato, "int") || ! strcmp(tipoDato, "unsigned") || ! strcmp(tipoDato, "long")) // [!] 
                    nuevoNodo -> valor.valEnt = 0;
                else if(! strcmp(tipoDato, "float") || ! strcmp(tipoDato, "double"))
                    nuevoNodo -> valor.valReal = 0;
                else if(! strcmp(tipoDato, "char"))
                    nuevoNodo -> valor.valChar = "NULL";
            break;
        case TIPO_FUNC:
            nuevoNodo -> valor.func = NULL;
            break;
    }

    nuevoNodo -> sig = NULL;

    return nuevoNodo;
}

void insertarSimbolo(Simbolo* nuevoSimbolo){
    
    Simbolo* nuevoNodo = devolverSimbolo(nuevoSimbolo -> nombre);

    if(! nuevoNodo){ // [!] Si no esta declarado dentro de la TS, genero un símbolo y lo inserto ordenado

        nuevoNodo = nuevoSimbolo;

        Simbolo* aux1 = tablaSimbolos;
        Simbolo* aux2;

        while(aux1 != NULL && strcmp(toUpper(nuevoNodo -> nombre), toUpper(aux1 -> nombre)) > 0){
            aux2 = aux1;
            aux1 = aux1 -> sig;
        }

        if(tablaSimbolos == aux1)
            tablaSimbolos = nuevoNodo;
        else
            aux2 -> sig = nuevoNodo;
        nuevoNodo -> sig = aux1;
    }    
}

Funcion* crearParametro(char* parametro){
    Funcion* nuevoParam = (Funcion*) malloc (sizeof(Funcion));
    nuevoParam -> tipoDatoParam = strdup(parametro);
    nuevoParam -> sig = NULL;

    puts("Creo parametro.");

    return nuevoParam;
}

void insertarParametro(Funcion** listaParametros, char* parametro){
    Funcion* aux = crearParametro(parametro);

    if(*listaParametros == NULL)
        *listaParametros = aux;
    else
    {
        Funcion* temp = *listaParametros;
        while(temp->sig != NULL)
            temp = temp->sig;
        
        aux->sig = temp->sig;
        temp->sig = aux;
    }  
}

Simbolo* devolverSimbolo(char* nombreID){
    Simbolo* aux = tablaSimbolos;

    while (aux != NULL){
        if (! strcmp(nombreID, aux -> nombre))
            return aux;
        aux = aux -> sig;
    }
    return NULL;

    /*

    for(Simbolo* aux = tablaSimbolos; aux != NULL; aux = aux -> sig)   --> [!] Otra forma de hacer devolverSimbolo()
        if (! strcmp(nombreID, aux -> nombre))
            return aux;
    
    return NULL;
    
    */
}

void mostrarTabla(FILE* archivoSalida){

    unsigned masLargo = encontrarMasLargo();
    char* centrado;
    if(! masLargo % 2)
        centrado = strdup(cantidadDeEspacios(masLargo / 2));
    else
        centrado = strdup(cantidadDeEspacios(masLargo / 2 - 1));

    fprintf(archivoSalida, "\n");
    fprintf(archivoSalida, "%s╔═══════════════════╗ \n", centrado);
    fprintf(archivoSalida, "%s║ Tabla de Simbolos ║ \n", centrado);
    fprintf(archivoSalida, "%s╚═══════════════════╝ \n", centrado);
    fprintf(archivoSalida, "\n");

    for(Simbolo* aux = tablaSimbolos; aux != NULL; aux = aux -> sig){
        
        char* espacios = strdup(cantidadDeEspacios(masLargo - strlen(aux -> nombre)));
        fprintf(archivoSalida, "ID: %s %s", aux -> nombre, espacios);
        
        switch(aux -> tipoID){
            case TIPO_VAR: 
                if(! strcmp(aux -> tipoDato, "int") || ! strcmp(aux -> tipoDato, "unsigned") || ! strcmp(aux -> tipoDato, "long")) // [!] 
                    fprintf(archivoSalida, " - Valor: %d\n", aux->valor.valEnt);
                else if(! strcmp(aux -> tipoDato, "float") || ! strcmp(aux -> tipoDato, "double"))
                    fprintf(archivoSalida, " - Valor: %.4f\n", aux -> valor.valReal);
                else if(! strcmp(aux -> tipoDato, "char"))
                    fprintf(archivoSalida, " - Valor: %s\n", aux -> valor.valChar);
                break;
            case TIPO_FUNC:
                    mostrarParametros(archivoSalida, aux -> valor.func);
                break;
            default:
                break;
        }
    }
}

void mostrarParametros(FILE* archivoSalida, Funcion* listaParametros){
    fprintf(archivoSalida, " - Parametro/s: (");
    for(Funcion* aux = listaParametros; aux != NULL; aux = aux -> sig){
        
        if(aux -> sig == NULL) // [!] Condicional para saber si es el ultimo valor de la lista de parametros 
            fprintf(archivoSalida, "%s", aux -> tipoDatoParam);
        else        
            fprintf(archivoSalida, "%s, ", aux -> tipoDatoParam);
    }
    fprintf(archivoSalida, ")");
}

/* 

void mostrarParametros(FILE* archivoSalida, Funcion* listaParametros){
    fprintf(archivoSalida, " - Parametro/s: (");
    for(Funcion* aux = listaParametros; aux != NULL; aux = aux -> sig){
        printf(archivoSalida, "%s", aux -> tipoDatoParam);
        if(aux -> sig)
            fprintf(archivoSalida, ", ");
    }
    fprintf(archivoSalida, ")");
}

*/

char* toUpper(char* nombreID){
    char* temporal = strdup(nombreID);
    return strupr(temporal);
}

void cambiarValor(Simbolo* simbolo, TipoValor valorNuevo) {
    if(! strcmp(simbolo -> tipoDato, "int") || ! strcmp(simbolo -> tipoDato, "unsigned") || ! strcmp(simbolo -> tipoDato, "long")) 
        simbolo->valor.valEnt = valorNuevo.valEnt;
    else if(! strcmp(simbolo -> tipoDato, "float") || ! strcmp(simbolo -> tipoDato, "double"))
        simbolo -> valor.valReal = valorNuevo.valReal;
    else if(! strcmp(simbolo -> tipoDato, "char"))
        simbolo -> valor.valChar = strdup(valorNuevo.valChar);
}

unsigned encontrarMasLargo()
{
    unsigned maximo = 0;

    for(Simbolo* p = tablaSimbolos; p != NULL; p = p -> sig){
        unsigned largo = strlen(p -> nombre);
        if(maximo < largo)
            maximo = largo;
    }

    return maximo;
}

char* cantidadDeEspacios(unsigned maximo)
{
    char* string = " ";
    int largo = strlen(string);
    char* resultado = malloc(largo * maximo + 1);

    for (int i = 0 ; i < maximo ; i++)
        memcpy(resultado + i * largo, string, largo);
    resultado[largo * maximo] = '\0';

    return resultado;
}