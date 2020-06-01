#include <stdio.h>
#include <stdlib.h>

enum{Zero, To1_9, Operators, ParenthesesOpen, ParenthesesClose}; // Números asociados a los caracteres leídos
enum{Q0, Q1, Q2, EstadoError};                                   // Nombres de Estados
enum{SignoPeso, REnPila, Epsilon};                              // Nombres asignados a valores de la pila

typedef struct node     // Struct de nodo
{
    char data;          // Guarda un caracter
    struct node* next;  // Puntero a nodo
} Node;

typedef struct status_topStack  // Struct de estado y cima
{
    short actualStatus;         // Guarda el estado actual
    short topStack;             // Guarda lo que tiene que ir en la pila
} StatStack;

Node* newNode(char);                // Crea un nodo
void pushStack(Node**, char);       // Agregar nodo a pila
char peekStack(Node*);              // Muestra cima de pila sin eliminarla
char popStack(Node**);              // Sacar cima de pila
short topePila(Node*);              // Devuelve un número según lo que haya en la cima de pila
short columnPosition(char);         // Dependiendo el caracter que lee, decide asignar un número específico
StatStack fillStruct(short, short); // Rellena el struct

int main()
{
    Node* stack = NULL; // Crea una pila
    pushStack(&stack, '$');  // Seteo '$' como piso de pila

    StatStack eLectura = {Q0, SignoPeso};   // Estado de Inicio del AFP

    StatStack AFPExpresionesAritmeticas[4][2][5] =  // [Estado Actual] [Cima de Pila] [Caracter Leido]
        {
            {  // Q0
                {   // '$'
                    fillStruct(EstadoError, SignoPeso),
                    fillStruct(Q1, SignoPeso), 
                    fillStruct(EstadoError, SignoPeso),
                    fillStruct(Q0, REnPila),
                    fillStruct(EstadoError, SignoPeso)
                },
                {   // 'R'
                    fillStruct(EstadoError, REnPila),
                    fillStruct(Q1, REnPila), 
                    fillStruct(EstadoError, REnPila),
                    fillStruct(Q0, REnPila),
                    fillStruct(EstadoError, REnPila)
                }  
            },
            {   //Q1 
                {   // '$'
                    fillStruct(Q1, SignoPeso),
                    fillStruct(Q1, SignoPeso),
                    fillStruct(Q0, SignoPeso),
                    fillStruct(EstadoError, SignoPeso),
                    fillStruct(EstadoError, SignoPeso)
                },
                {   // 'R'
                    fillStruct(Q1, REnPila),
                    fillStruct(Q1, REnPila),
                    fillStruct(Q0, REnPila),
                    fillStruct(EstadoError, REnPila),
                    //fillStruct(Q2, topePila(stack))
                    fillStruct(Q2, Epsilon)
                }  
            }
            ,
            {   //Q2
                {   // '$'
                    fillStruct(EstadoError, SignoPeso),
                    fillStruct(EstadoError, SignoPeso),
                    fillStruct(Q0, SignoPeso),
                    fillStruct(EstadoError, SignoPeso),
                    fillStruct(EstadoError, SignoPeso)
                }, 
                {   // 'R'
                    fillStruct(EstadoError, REnPila),
                    fillStruct(EstadoError, REnPila),
                    fillStruct(Q0, REnPila),
                    fillStruct(EstadoError, REnPila),
                    //fillStruct(Q2, topePila(stack))
                    fillStruct(Q2, Epsilon)
                }
            },
            {   //EstadoError
                {   // '$'
                    fillStruct(EstadoError, SignoPeso),
                    fillStruct(EstadoError, SignoPeso),
                    fillStruct(EstadoError, SignoPeso),
                    fillStruct(EstadoError, SignoPeso),
                    fillStruct(EstadoError, SignoPeso)
                },
                {   // 'R'
                    fillStruct(EstadoError, REnPila),
                    fillStruct(EstadoError, REnPila),
                    fillStruct(EstadoError, REnPila),
                    fillStruct(EstadoError, REnPila),
                    fillStruct(EstadoError, REnPila)
                }  
            }
        };

    puts("Ingrese una expresion aritmetica:");
    fflush(stdin);                   //Limpio el buffer

    char auxCaracter = fgetc(stdin); // Lee y elimina caracteres de la expresion

    while(auxCaracter != '\n')       // Mientras no haya terminado
    {
        if(auxCaracter != ' ')       // Saltear espacios
        {   
            // Guardo lo leído en variables
            short estadoActual = eLectura.actualStatus;
            short cimaPila = eLectura.topStack;
            short caracterLeido = columnPosition(auxCaracter);

            if(cimaPila == Epsilon) //Si leo Epsilon dentro de la matriz, leo la cima de la pila y lo guardo
                cimaPila = topePila(stack);

            char elemCima = popStack(&stack);   //Guardo el valor del tope de pila eliminando el nodo
            
            if(estadoActual == Q0) // (Q0, $) || (Q0,R)
            {
                if(caracterLeido == ParenthesesOpen)    // Si lee un '('
                {
                    pushStack(&stack, elemCima);    
                    pushStack(&stack, 'R');
                }
                else
                    pushStack(&stack, elemCima); 
            }
            else if((estadoActual == Q1 || estadoActual == Q2) && cimaPila == REnPila) // (Q1,R) || (Q2,R)   
            {
                    if(caracterLeido != ParenthesesClose)   // Si no lee un ')'
                        pushStack(&stack, elemCima); 
            }
            else
                pushStack(&stack, elemCima);
            
            eLectura = AFPExpresionesAritmeticas[estadoActual][cimaPila][caracterLeido]; // Actualizo el estado
        }
        
        auxCaracter = fgetc(stdin);  // Pasa al siguiente caracter
    }

    // Discrimino los estados finales
    if((eLectura.actualStatus == Q1 || eLectura.actualStatus == Q2) && topePila(stack) == SignoPeso) // (Q1, $) || (Q2, $)
        puts("Es sintacticamente correcto.");
    else
        puts("No es sintacticamente correcto.");

    char option;

    printf("Desea volver a compilar el programa? (S/N): ");
    scanf("%c", &option);

    if(option == 's' || option == 'S')  // Si elige que sí
        main(); // Vuelvo a llamar al main si elige el cliente volver a compilar

    return 0;   // Termina el programa
}

Node* newNode(char data)
{
    Node* newNode= (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void pushStack(Node** stack, char data)
{
    Node* p = newNode(data);
    p->next = *stack;
    *stack = p;

}

char peekStack(Node* p)
{
    if(p != NULL)
        return p->data;
}

char popStack(Node** stack)
{   
    if(*stack != NULL)
    {
        char letter;
        Node* p = *stack;
        letter = p->data;

        *stack = (*stack)->next;
        free(p);

        return letter;
    }

}

short columnPosition(char letter)
{
    short posColumn;

    if(letter == '0')
        posColumn = Zero;
    else if(letter >= '1' && letter <= '9')
        posColumn = To1_9;
    else if(letter == '+' || letter == '-' || letter == '*' || letter == '/')
        posColumn = Operators;
    else if(letter == '(')
        posColumn = ParenthesesOpen;
    else if(letter == ')')
        posColumn = ParenthesesClose;
    else
        return -1;

    return posColumn;
}

StatStack fillStruct(short status, short top)
{
    StatStack stat_top;
    stat_top.actualStatus = status;
    stat_top.topStack = top;

    return stat_top;
} 

short topePila (Node* stack)
{
    char aux = peekStack(stack);

    if(aux == 'R')
        return REnPila;
    else
        return SignoPeso;
}