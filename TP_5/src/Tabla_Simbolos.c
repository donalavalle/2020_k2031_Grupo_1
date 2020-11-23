#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#include "Tabla_Simbolos.h"

Simbolo* crearSimbolo(char* tipoDato, char* nombreID, int tipoID){
    Simbolo* nuevoNodo = (Simbolo*) malloc (sizeof(Simbolo));

    nuevoNodo -> nombre   = strdup(nombreID);
    nuevoNodo -> tipoDato = strdup(tipoDato);
    nuevoNodo -> tipoID   = tipoID;
    nuevoNodo -> valor    = limpiarUnion();
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

    unsigned masLargo;

    if(tablaSimbolos) {
        masLargo = encontrarMasLargo();
        char* centrado;
        if(masLargo == 1)
            centrado = strdup(" ");
        else if(! masLargo % 2)
            centrado = strdup(cantidadDeEspacios(masLargo / 2));
        else
            centrado = strdup(cantidadDeEspacios(masLargo / 2 - 1));
            
        fprintf(archivoSalida, "\n");
        fprintf(archivoSalida, "%s╔═══════════════════╗ \n", centrado);
        fprintf(archivoSalida, "%s║ Tabla de Simbolos ║ \n", centrado);
        fprintf(archivoSalida, "%s╚═══════════════════╝ \n", centrado);
        fprintf(archivoSalida, "\n");
    }

    else {
        fprintf(archivoSalida, "\n");
        fprintf(archivoSalida, "╔═══════════════════╗ \n");
        fprintf(archivoSalida, "║ Tabla de Simbolos ║ \n");
        fprintf(archivoSalida, "╚═══════════════════╝ \n");
        fprintf(archivoSalida, "\n");
    }

    fprintf(archivoSalida,"• Lista de Variables: \n");
    for(Simbolo* aux = tablaSimbolos; aux != NULL; aux = aux -> sig){
        char* espacios = strdup(cantidadDeEspacios(masLargo - strlen(aux -> nombre)));
        if (aux -> tipoID == TIPO_VAR){
            fprintf(archivoSalida, " - Tipo de Dato: \'%s\' ", aux -> tipoDato);
            fprintf(archivoSalida, " - Nombre de Variable: %s %s", aux -> nombre, espacios);
            if(! strcmp(aux -> tipoDato, "int")) // [!] 
                fprintf(archivoSalida, " - Valor: %d\n", aux->valor.valEnt);
            else if(! strcmp(aux -> tipoDato, "float"))
                fprintf(archivoSalida, " - Valor: %f\n", aux -> valor.valReal);
            else if(! strcmp(aux -> tipoDato, "char"))
                fprintf(archivoSalida, " - Valor: \'%c\'\n", aux -> valor.valChar); // le agregamos las comillas para no confundir después con algún identificador 
            else if(! strcmp(aux -> tipoDato, "char*"))
                fprintf(archivoSalida, " - Valor: %s\n", aux -> valor.valString); //Hicimos la separación entre char y string
            else
                fprintf(archivoSalida, " - Valor: No corresponde a ningun tipo de valor que se toma en cuenta, Octi.\n");                
        }
    }
    fprintf(archivoSalida,"\n• Lista de Funciones: \n");
    for(Simbolo* aux = tablaSimbolos; aux != NULL; aux = aux -> sig){
        if (aux -> tipoID == TIPO_FUNC){
        fprintf(archivoSalida, " - Retorno : %s", aux -> tipoDato);
        fprintf(archivoSalida, " - Nombre de Funcion: %s", aux -> nombre);
        mostrarParametros(archivoSalida, aux -> valor.func);
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
    fprintf(archivoSalida, ")\n");
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

// [!] Se copia los valores que tenga valorNuevo al union del Simbolo [!] .
void cambiarValor(Simbolo* simbolo, TipoValor valorNuevo) {
    if(! strcmp(simbolo -> tipoDato, "int")) 
        simbolo->valor.valEnt = valorNuevo.valEnt;
    else if(! strcmp(simbolo -> tipoDato, "float"))
        simbolo -> valor.valReal = valorNuevo.valReal;
    else if(! strcmp(simbolo -> tipoDato, "char"))
        simbolo -> valor.valChar = valorNuevo.valChar;
    else if(! strcmp(simbolo -> tipoDato, "char*"))
        simbolo -> valor.valString = strdup(valorNuevo.valString);
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

TipoValor limpiarUnion() {
    TipoValor unionLimpia;

    unionLimpia.valEnt    = 0;
    unionLimpia.valReal   = 0.0;
    unionLimpia.valChar   = '\0';
    unionLimpia.valString = NULL;
    unionLimpia.func      = NULL;
    
    return unionLimpia;
}

void sumarLinea() {
    cantidadDeLineas++;
}

unsigned cantidadDeParametros(Funcion* parametros) {
    unsigned cantidad = 0;

    for(Funcion* aux = parametros; aux != NULL; aux = aux -> sig)
        cantidad++;

    return cantidad;
}

void verificarParametros(Simbolo* unaFuncion, Funcion* unaListaDeParam, FILE* archivoSalida) {
    Funcion* parametros = unaFuncion -> valor . func;

    if(cantidadDeParametros(parametros) != cantidadDeParametros(unaListaDeParam)){
        char* mensaje =  strdup("La cantidad de parametros ingresados no coinciden en la funcion '");
        strcat(mensaje, unaFuncion -> nombre);
        strcat(mensaje, "'");
        insertarError(&erroresSemanticos, mensaje);
        // insertarError(&erroresSemanticos, "La cantidad de parametros ingresados no coinciden en la funcion");
        //fprintf(archivoSalida, "Error en linea %d: La cantidad de parametros ingresados no coinciden en la funcion \'%s\'.\n", cantidadDeLineas, unaFuncion -> nombre);
    } 
    else
        for(Funcion* aux = parametros; aux != NULL; aux = aux -> sig){
            if(strcmp(unaListaDeParam -> tipoDatoParam, aux -> tipoDatoParam)){
                insertarError(&erroresSemanticos, "El tipo de dato de los argumentos ingresados no coinciden con los esperados por la funcion");
                //fprintf(archivoSalida, "Error en linea %d: El tipo de dato de los argumentos ingresados no coinciden con los esperados por la funcion \'%s\'.\n", cantidadDeLineas, unaFuncion -> nombre);
                break;
            }   
            unaListaDeParam = unaListaDeParam -> sig;
        }
}

void generarReporte(FILE* reporteGeneral) {
    mostrarTabla(reporteGeneral);
    fprintf(reporteGeneral,"• Errores Lexicos: \n");
    mostrarError(erroresLexicos, reporteGeneral); // [❗] Muestro los errores LEXICOS
    fprintf(reporteGeneral,"• Errores Semanticos: \n");
    mostrarError(erroresSemanticos, reporteGeneral); // [❗] Muestro los errores SEMÁNTICOS
}

Error* crearError(char* mensajeDeError) {
    Error* nuevoError = (Error*) malloc (sizeof(Error));
    nuevoError -> mensajeError = strdup(mensajeDeError);
    nuevoError -> numeroDeLinea = cantidadDeLineas;
    nuevoError -> sig = NULL;  
    return nuevoError;
}

void insertarError(Error** listaDeErrores, char* mensajeDeError) {
    Error* aux = crearError(mensajeDeError);

    if(*listaDeErrores == NULL)
        *listaDeErrores = aux;
    else
    {
        Error* temp = *listaDeErrores;
        while(temp->sig != NULL)
            temp = temp->sig;
        
        aux->sig = temp->sig;
        temp->sig = aux;
    }
}

void mostrarError(Error* listaError, FILE* archivoSalida) {
    for(Error* aux = listaError; aux != NULL; aux = aux -> sig){
        fprintf(archivoSalida, " - Error en linea %d: %s.\n", aux -> numeroDeLinea, aux -> mensajeError);
    }
}