#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AnalizadorSemantico.h"

Simbolo* crearSimbolo(char* tipoDato, char* nombreID, int tipoID){
    Simbolo* nuevoNodo = (Simbolo*) malloc (sizeof(Simbolo));

    nuevoNodo -> nombre   = strdup(nombreID);
    nuevoNodo -> tipoDato = strdup(tipoDato);
    nuevoNodo -> tipoID   = tipoID;

    switch(tipoID){
        default:
            break;
        case TIPO_VAR:
                if(! strcmp(tipoDato, "int") || ! strcmp(tipoDato, "unsigned") || ! strcmp(tipoDato, "long"))
                    nuevoNodo -> valor.valEnt = 0;
                else if(! strcmp(tipoDato, "float") || ! strcmp(tipoDato, "double"))
                    nuevoNodo -> valor.valReal = 0;
                else if(! strcmp(tipoDato, "char"))
                    nuevoNodo -> valor.valChar = " ";
            break;
        case TIPO_FUNC:
            nuevoNodo -> valor.func = NULL;
            break;
    }

    nuevoNodo -> sig = NULL;

    return nuevoNodo;
}


void insertarSimbolo(char* tipoDato, char* nombreID, int tipoID){
    
    Simbolo* nuevoNodo = devolverSimbolo(nombreID);

    if(! nuevoNodo){ // Si no esta declarado dentro de la TS, genero un símbolo y lo inserto ordenado
        
        Simbolo* aux1 = tablaSimbolos;
        Simbolo* aux2;

        while(aux1 != NULL && strcmp(toUpper(nombreID), toUpper(aux1 -> nombre)) > 0){
            aux2 = aux1;
            aux1 = aux1 -> sig;
        }

        if(tablaSimbolos == aux1)
            tablaSimbolos = nuevoNodo;
        else
            aux2->sig = nuevoNodo;
        nuevoNodo -> sig = aux1;
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

    /* for(Simbolo* aux = tablaSimbolos; aux != NULL; aux = aux -> sig)
        if (! strcmp(nombreID, aux -> nombre))
            return aux;
    
    return NULL; */
}

/*

void mostrarTabla(){
}

*/

char* toUpper(char* nombreID){
    char* temporal = strdup(nombreID);

    return strupr(temporal);
}