#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char* dato;
    int acum;
    struct node* sig;
} Nodo;

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

Nodo* nuevoNodo(char* dato)
{
    Nodo* newNode= (Nodo*) malloc(sizeof(Nodo));
    newNode->dato = (char*) malloc((strlen(dato) + 1) * sizeof(char));
    strcpy(newNode->dato, dato);
    newNode->acum = 1;
    newNode->sig = NULL;

    return newNode;
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

/* void insertToListLine(Node** list, char* dato, int line)
{
    Node* p = newNode(dato);
    p->acum = line;
    Node* temp = *list;
    if(*list == NULL)
        *list = p;
    else
    {
        while(temp->sig != NULL)
            temp = temp->sig;
        p->sig = temp->sig;
        temp->sig = p;
    }
}
 */


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
        if(p->sig != NULL)
            fprintf(archivo, "%s -> ", p->dato);
        else
            fprintf(archivo, "%s\n", p->dato);
        p = p -> sig;
    }
}

void mostrarAcum(Nodo* list, FILE* archivo)
{
    Nodo* p = list;

    while(p != NULL)
    {   
        if(p->sig != NULL)
            fprintf(archivo, "%d -> ", p->acum);
        else
            fprintf(archivo, "%d\n", p->acum);
        p = p -> sig;
    }
}

void mostrar(char* elem, char* acum, Nodo* list, FILE* archivo)
{
    Nodo* p = list;

    while(p != NULL)
    {   
        fprintf(archivo, " - %s: %s\t\t%s: %d\n", elem, p->dato, acum, p->acum);
        p = p -> sig;
    }
}

void mostrarEnDecimal(char* texto, Nodo* lista, short base, FILE* archivo)
{
    Nodo* p = lista;

    while(p != NULL)
    {   
        fprintf(archivo, " - %s: %s\t\tValor en decimal: %d\n", texto, p->dato, strtoll(p->dato, NULL, base));
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

    fprintf(archivo, "La sumatoria de los decimales es: %d\n", acum);
}

void parteEnteraYMantisa(Nodo* lista, FILE* archivo)
{
    Nodo* p = lista;

    while(p != NULL)
    {
        double temp = atof(p->dato);
        int parteEntera = (int) temp;
        fprintf(archivo, "Constante real: %s  ", p->dato);
        fprintf(archivo, "Parte entera: %d  ", parteEntera);
        fprintf(archivo, "Mantisa: %f\n\n", temp - parteEntera);

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

unsigned cantSaltosLinea = 1;

void generarReporte(FILE* archivo)
{
    fprintf(archivo, "----- Reporte -----\n\n");
    fprintf(archivo, "Lista de identificadores:\n");
    mostrar("Identificador", "Cantidad de veces que aparece", listaDeIdentificadores, archivo);
    
    fprintf(archivo, "\nLista de literales cadena:\n");
    mostrar("Literal cadena", "Largo", listaDeLiterales, archivo);
    fprintf(archivo, "\nLista de palabras reservadas: ");
    mostrarLista(listaDePalabrasReservadas, archivo);
    
    fprintf(archivo, "\nLista de constantes octales:\n");
    mostrarEnDecimal("Constante octal", listaDeOctales, 8, archivo);
    
    fprintf(archivo, "\nLista de constantes hexadecimales:\n");
    mostrarEnDecimal("Constante hexadecimal", listaDeHexadecimales, 16, archivo);

    fprintf(archivo, "\nLista de constantes decimales: ");
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
}