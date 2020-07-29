#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char* dato;
    int acum;
    struct node* sig;
} Nodo;

Nodo* listaDeIdentificadores = NULL;
Nodo* listaDeLiterales = NULL;
Nodo* listaDePalabrasReservadas = NULL;
Nodo* listaDeOctales = NULL;
Nodo* listaDeHexadecimales = NULL;
Nodo* listaDeDecimales = NULL;
Nodo* listaDeReales = NULL;
Nodo* listaDeCaracteres = NULL;
Nodo* listaDeOperYPunt = NULL;
Nodo* listaDeComentariosDeLinea = NULL;
Nodo* listaDeComentariosDeBloque = NULL;
Nodo* listaDeErrores = NULL;

unsigned cantSaltosLinea = 1;
char* cadenaErronea = NULL;
unsigned errorFlag = 0;

Nodo* nuevoNodo(char* dato)
{
    Nodo* newNode= (Nodo*) malloc(sizeof(Nodo));
    newNode->dato = strdup(dato);
    newNode->acum = 1;
    newNode->sig = NULL;

    return newNode;
}

void insertarLinea(Nodo** lista, char* dato, int linea)
{
    Nodo* p = nuevoNodo(dato);
    p->acum = linea;
    Nodo* temp = *lista;
    if(*lista == NULL)
        *lista = p;
    else
    {
        while(temp->sig != NULL)
            temp = temp->sig;
        p->sig = temp->sig;
        temp->sig = p;
    }
}

void esError(char* charErroneo){
    if(cadenaErronea == NULL)
        cadenaErronea = strdup(charErroneo);
    else
    {
        char * ptr = malloc(strlen(charErroneo) + strlen(cadenaErronea) + 1);
        strcpy(ptr, cadenaErronea);
        strcat(ptr, charErroneo);
        cadenaErronea = strdup(ptr);
    }
    errorFlag = 1;
}

void finalDeError(){
    if (errorFlag)
    {
        insertarLinea(&listaDeErrores, cadenaErronea, cantSaltosLinea);
        cadenaErronea = NULL;
        errorFlag = 0;
    }
    errorFlag = 0;
}

int cantidadSaltosDeLinea(char* data)
{
    int cant= 0;
    int i = 0;
    while(data[i] != '\0')
    {
        if(data[i] == '\n')
            cant++;
        i++;
    }

    return cant;
}

short existeNodo(Nodo* list, char* dato)
{
    Nodo* p = list;
    
    while(p != NULL && strcmp(dato, p->dato) != 0)
        p = p->sig;
    if(p != NULL && strcmp(dato, p->dato) == 0)
        return 1;
    else
        return 0;
}

Nodo* buscarNodo(Nodo** list, char* dato)
{
    Nodo* p = *list;

    while(strcmp(dato, p->dato) != 0)
        p = p->sig;

    return p;
}

void insertarOrdenado(Nodo** list, char* dato)
{
    Nodo* p;

    if(!existeNodo(*list, dato))
    {
        p = nuevoNodo(dato);
        Nodo* aux1 = *list;
        Nodo* aux2;

        while(aux1 != NULL && strcmp(dato, aux1->dato) > 0)
        {
            aux2 = aux1;
            aux1 = aux1->sig;
        }

        if(*list == aux1)
            *list = p;
        else
            aux2->sig = p;
        p->sig = aux1;
    }
    else
    {
        p = buscarNodo(list, dato);
        p->acum += 1;
    }
}

void insertarEnLista(Nodo** lista, char* dato)
{
    Nodo* aux = nuevoNodo(dato);
    aux->acum = strlen(dato) - 2;

    if(*lista == NULL)
        *lista = aux;
    else
    {
        Nodo* temp = *lista;
        while(temp->sig != NULL)
            temp = temp->sig;
        
        aux->sig = temp->sig;
        temp->sig = aux;
    }  
}

void mostrarLista(Nodo* list, FILE* archivo)
{
    Nodo* p = list;
    
    while(p != NULL)
    {   
        unsigned limite = 0;

        while(limite != 16 && p != NULL)
        {
            if(p->sig != NULL)
                fprintf(archivo, "%s -> ", p->dato);
            else
                fprintf(archivo, "%s\n", p->dato);
            p = p -> sig;

            limite++;
        }
        if(p != NULL)
            fprintf(archivo, "\n");
    }
}

unsigned encontrarMaximo(Nodo* lista)
{
    Nodo* p = lista;
    unsigned maximo = 0;

    while(p != NULL)
    {
        unsigned largo = strlen(p->dato);
        if(maximo < largo)
            maximo = largo;
        p = p->sig;
    }

    return maximo;
}

unsigned encontrarMaxParteEntera(Nodo* lista)
{
    Nodo* p = lista;
    unsigned maximo = 0;

    while(p != NULL)
    {
        double temp = atof(p->dato);
        int parteEntera = (int) temp;

        char* buffer = (char*) malloc((strlen(p->dato) + 1) * sizeof(char));
        sprintf(buffer, "%d", parteEntera);

        unsigned largo = strlen(buffer);
        if(maximo < largo)
            maximo = largo;
        p = p->sig;
    }

    return maximo;
}

char* cantidadDeEspacios(unsigned maximo)
{
    char* espacio = " ";
    int largo = strlen(espacio);
    char* resultado = malloc(largo * maximo + 1);

    for (int i = 0 ; i < maximo ; i++)
        memcpy(resultado + i * largo, espacio, largo);
    resultado[largo * maximo] = '\0';

    return resultado;
}

void mostrar(char* elem, char* acum, Nodo* lista, FILE* archivo)
{
    Nodo* p = lista;

    while(p != NULL)
    {   
        unsigned maximo = encontrarMaximo(lista);
        char* cantidadEspacios = cantidadDeEspacios(maximo - strlen(p->dato));
        fprintf(archivo, " - %s: \'%s\' %s - %s: %d\n", elem, p->dato, cantidadEspacios, acum, p->acum);
        p = p -> sig;
    }
}

void mostrarEnDecimal(char* texto, Nodo* lista, short base, FILE* archivo)
{
    Nodo* p = lista;

    while(p != NULL)
    {   
        unsigned maximo = encontrarMaximo(lista);
        char* cantidadEspacios = cantidadDeEspacios(maximo - strlen(p->dato));
        fprintf(archivo, " - %s: %s %s - Valor en decimal: %d\n", texto, p->dato, cantidadEspacios, strtoll(p->dato, NULL, base));
        p = p -> sig;
    }
}

void sumaDeDecimales(Nodo* lista, FILE* archivo)
{
    Nodo* p = lista;
    int acum = 0;

    while(p != NULL)
    {
        acum += strtoll(p->dato, NULL, 10);
        p = p->sig;
    }

    fprintf(archivo, "\nLa sumatoria de los decimales es: %d\n", acum);
}

void cantidadDecimales(unsigned cantidad, float valor, FILE* archivo)
{
    if(cantidad > 8)
        cantidad = 8;

    switch(cantidad)
    {
        default:
        case 0:
            fprintf(archivo, " - Mantisa: 0.0\n");
            break;
        case 1:
            fprintf(archivo, " - Mantisa: %0.1f\n", valor);
            break;
        case 2:
            fprintf(archivo, " - Mantisa: %0.2f\n", valor);
            break;
        case 3:
            fprintf(archivo, " - Mantisa: %0.3f\n", valor);
            break;
        case 4:
            fprintf(archivo, " - Mantisa: %0.4f\n", valor);
            break;
        case 5:
            fprintf(archivo, " - Mantisa: %0.5f\n", valor);
            break;
        case 6:
            fprintf(archivo, " - Mantisa: %0.6f\n", valor);
            break;
        case 7:
            fprintf(archivo, " - Mantisa: %0.7f\n", valor);
            break;
        case 8:
            fprintf(archivo, " - Mantisa: %0.8f\n", valor);
            break;
    }
}

void parteEnteraYMantisa(Nodo* lista, FILE* archivo)
{
    Nodo* p = lista;

    while(p != NULL)
    {
        unsigned maximo = encontrarMaximo(lista);
        char* cantidadEspacios = cantidadDeEspacios(maximo - strlen(p->dato));

        double temp = atof(p->dato);
        
        char* decimales;
        strtoll(p->dato, &decimales, 10);
        int parteEntera = (int) temp;

        char* buffer = (char*) malloc((strlen(p->dato) + 1) * sizeof(char));
        sprintf(buffer, "%d", parteEntera);

        fprintf(archivo, " - Constante real: %s %s", p->dato, cantidadEspacios);

        maximo = encontrarMaxParteEntera(lista);
        cantidadEspacios = cantidadDeEspacios(maximo - strlen(buffer));

        fprintf(archivo, " - Parte entera: %d %s", parteEntera, cantidadEspacios);
        cantidadDecimales(strlen(decimales) - 1, temp - parteEntera, archivo);

        p = p->sig;
    }
}

void mostrarCaracteres(Nodo* lista, FILE* archivo)
{
    Nodo* p = lista;
    int i = 1;
    while(p != NULL)
    {
        fprintf(archivo, "%d) %s\n", i, p->dato);
        i++;
        p = p->sig;
    }
}

void mostrarComentario(Nodo* lista, FILE* archivo)
{
    Nodo* p = lista;

    while(p != NULL)
    {
        fprintf(archivo, "%s\n", p->dato);

        p = p->sig;
    }
}

void generarReporte(FILE* archivo)
{
    fprintf(archivo, "----- Reporte -----\n\n");
    fprintf(archivo, "Lista de identificadores:\n");
    mostrar("Identificador", "Cantidad de veces que aparece", listaDeIdentificadores, archivo);
    
    fprintf(archivo, "\nLista de literales cadena:\n");
    mostrar("Literal cadena", "Largo", listaDeLiterales, archivo);
    fprintf(archivo, "\nLista de palabras reservadas:\n");
    mostrarLista(listaDePalabrasReservadas, archivo);
    
    fprintf(archivo, "\nLista de constantes octales:\n");
    mostrarEnDecimal("Constante octal", listaDeOctales, 8, archivo);
    
    fprintf(archivo, "\nLista de constantes hexadecimales:\n");
    mostrarEnDecimal("Constante hexadecimal", listaDeHexadecimales, 16, archivo);

    fprintf(archivo, "\nLista de constantes decimales:\n");
    mostrarLista(listaDeDecimales, archivo);
    sumaDeDecimales(listaDeDecimales, archivo);
    
    fprintf(archivo, "\nLista de constantes reales:\n");
    parteEnteraYMantisa(listaDeReales, archivo);

    fprintf(archivo, "\nLista de constantes caracter:\n");
    mostrarCaracteres(listaDeCaracteres, archivo);

    fprintf(archivo, "\nLista de operadores y puntuadores:\n");
    mostrar("Operador/Puntuador", "Cantidad de veces que aparece", listaDeOperYPunt, archivo);

    fprintf(archivo, "\nLista de comentarios de linea:\n");
    mostrarComentario(listaDeComentariosDeLinea, archivo);

    fprintf(archivo, "\nLista de comentarios de bloque:\n");
    mostrarComentario(listaDeComentariosDeBloque, archivo);

    fprintf(archivo, "\nLista de caracteres/cadenas erroneas:\n");
    mostrar("Caracter/Cadena", "Aparece en linea", listaDeErrores, archivo);

    free(listaDeIdentificadores);
    free(listaDeLiterales);
    free(listaDePalabrasReservadas);
    free(listaDeOctales);
    free(listaDeHexadecimales);
    free(listaDeDecimales);
    free(listaDeReales);
    free(listaDeCaracteres);
    free(listaDeOperYPunt);
    free(listaDeComentariosDeLinea);
    free(listaDeComentariosDeBloque);
    free(listaDeErrores);
}