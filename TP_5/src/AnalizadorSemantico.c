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
    fprintf(archivoSalida, "\n - Tabla de Simbolos -\n");

    for(Simbolo* aux = tablaSimbolos; aux != NULL; aux = aux -> sig){
        fprintf(archivoSalida, "Identificador: %s ", aux -> nombre);
        
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

void modificarTabla(Simbolo* simboloACambiar){
    Simbolo* temp = devolverSimbolo(simboloACambiar -> nombre);

    printf("Valor Anterior: %d\tNuevo Valor:%d", temp -> valor.valEnt, simboloACambiar -> valor.valEnt);
    eliminarSimbolo(temp);
    //insertarSimbolo(simboloACambiar);
}

char* toUpper(char* nombreID){
    char* temporal = strdup(nombreID);
    return strupr(temporal);
}

void eliminarSimbolo(Simbolo* simboloAEliminar){
    Simbolo* temp = devolverSimbolo(simboloAEliminar -> nombre);

    if(temp){
        
        Simbolo* aux = tablaSimbolos;

        if(aux == temp)
            tablaSimbolos = aux -> sig;
        else{
            while(aux -> sig != temp) // Recorre la lista hasta encontrar que el siguiente simbolo sea el simbolo a eliminar
                aux = aux -> sig;

            aux -> sig = temp -> sig; // Hace el cambio de punteros 
        }
        
        free(temp); // Elimina el nodo 
    }
}

void modificarTabla(Simbolo* simboloAModificar, TipoValor valorModificado){
    simboloAModificar -> valor = valorModificado;
}