#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        
    Simbolo* var1 = crearSimbolo("int", "helloWorld", TIPO_VAR);
    Simbolo* var2 = crearSimbolo("char", "octi", TIPO_VAR);

    insertarSimbolo(var2);
    insertarSimbolo(var1);                  // [!!] Para mejorar el manejo de la TS, pasaríamos por
                                            //      parámetro el símbolo

    mostrarTabla(archivoSalida);

    temp = devolverSimbolo("helloWorld");   // [!]  Si quiero cambiar el valor de un símbolo que ya tenía,
                                            //      devuelvo el símbolo
    if(temp){
        
    }

    mostrarTabla(archivoSalida);

    fclose(archivoSalida);
}