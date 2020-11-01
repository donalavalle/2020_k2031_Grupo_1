#include <stdio.h>
#include <stdlib.h>
#include "AnalizadorSemantico.h"

Simbolo* tablaSimbolos;

int main(){


    FILE* archivoSalida = fopen("Salida.txt", "w");

    Simbolo* temp;
    /* Funcion* listaParametros = NULL;
    
    insertarParametro(&listaParametros, "int");
    insertarParametro(&listaParametros, "char");
    insertarParametro(&listaParametros, "float");

    mostrarParametros(archivoSalida, listaParametros); */
        
    Simbolo* temp = crearSimbolo("int", "helloWorld", TIPO_VAR);

    insertarSimbolo(temp);                  // [!!] Para mejorar el manejo de la TS, pasaríamos por
                                            //      parámetro el símbolo

    temp = devolverSimbolo("helloWorld");   // [!]  Si quiero cambiar el valor de un símbolo que ya tenía,
                                            //      devuelvo el símbolo
    if(temp){                               // [!]  Si existe el símbolo dentro de la TS, paso a modificar
        temp->valor.valEnt = 4;             // [!]  Modifico el valor del union que quiero
        modificarTabla(temp);               // [!!] Inserto el símbolo cambiado (Debería buscar el símbolo
                                            //      viejo con el mismo nombre, eliminarlo e insertar el nuevo)
    }

    mostrarTabla(archivoSalida);

    fclose(archivoSalida);

    return 0;
}


// TODO: Insertar, de ser necesario, los simbolos en la TS con sus valores correspondientes