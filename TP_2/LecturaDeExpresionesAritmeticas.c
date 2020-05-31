#include <stdio.h>
#include <stdlib.h>

enum{Zero, To1_9, Operators, ParenthesesOpen, ParenthesesClose}; // Números asociados a los caracteres leídos
enum{Q0, Q1, Q2, EstadoError};                                   // Nombres de Estados
enum{SignoPeso, RInStack};                              // Nombres asignados a valores de la pila

typedef struct node
{
    char data;
    struct node* next;
} Node;

typedef struct status_topStack
{
    short actualStatus; // Guarda el stado actual
    short topStack;     // Guarda lo que tiene que ir en la pila
} StatStack;

Node* newNode(char);                    // Crea un nodo
void pushStack(Node**, char);           // Agregar a pila
char peekStack(Node*);                  // Muestra cima de pila sin sacarla (No usamos la función)
char popStack(Node**);                  // Sacar cima de pila
void initStack(Node**);                 // Inicia la pila con el '$'
void showStack(Node*);                  // Muestra el contenido de pila (No lo usamos)
short topePila(Node*);                   // Devuelve un número según lo que haya en la cima de pila
short columnPosition(char);             // Dependiendo el caracter que lee, decide asignar un número específico
StatStack fillStruct(short, short);     // Rellena el struct dependiendo el estado

int main()
{
    Node* stack = NULL;
    initStack(&stack); 

    StatStack eLectura = {Q0, SignoPeso};

    StatStack AFPExpresionesAritmeticas[4][2][5] =  // [Estado Actual] [Cima de Pila] [Caracter Leido]
        {
            {  // Q0
                {   // '$'
                    fillStruct(EstadoError, SignoPeso),
                    fillStruct(Q1, SignoPeso), 
                    fillStruct(EstadoError, SignoPeso),
                    fillStruct(Q0, RInStack),
                    fillStruct(EstadoError, SignoPeso)
                },
                {   // 'R'
                    fillStruct(EstadoError, RInStack),
                    fillStruct(Q1, RInStack), 
                    fillStruct(EstadoError, RInStack),
                    fillStruct(Q0, RInStack),
                    fillStruct(EstadoError, RInStack)
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
                    fillStruct(Q1, RInStack),
                    fillStruct(Q1, RInStack),
                    fillStruct(Q0, RInStack),
                    fillStruct(EstadoError, RInStack),
                    fillStruct(Q2, topePila(stack))
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
                    fillStruct(EstadoError, RInStack),
                    fillStruct(EstadoError, RInStack),
                    fillStruct(Q0, RInStack),
                    fillStruct(EstadoError, RInStack),
                    fillStruct(Q2, topePila(stack))
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
                    fillStruct(EstadoError, RInStack),
                    fillStruct(EstadoError, RInStack),
                    fillStruct(EstadoError, RInStack),
                    fillStruct(EstadoError, RInStack),
                    fillStruct(EstadoError, RInStack)
                }  
            }
        };

    puts("Ingrese una expresion aritmetica:");
    fflush(stdin);
    char auxCaracter = fgetc(stdin); // Lee y elimina caracteres de la expresion

    while(auxCaracter != '\n')       // Mientras no haya terminado
    {
        if(auxCaracter != ' ')       // Saltear espacios
        {            
            short estadoActual = eLectura.actualStatus;
            short cimaPila = eLectura.topStack;
            short caracterLeido = columnPosition(auxCaracter);

            char elemCima = popStack(&stack);
            
            if(estadoActual == Q0) // (Q0, $) || (Q0,R)
            {
                if(caracterLeido == ParenthesesOpen)
                {
                    pushStack(&stack, elemCima);
                    pushStack(&stack, 'R');
                }
                else
                    pushStack(&stack, elemCima); 
            }
            else if((estadoActual == Q1 || estadoActual == Q2) && cimaPila == RInStack) // (Q1,R) || (Q2,R)   
            {
                    if(caracterLeido != ParenthesesClose)
                        pushStack(&stack, elemCima); 
            }
            else
                pushStack(&stack, elemCima);
            
            eLectura = AFPExpresionesAritmeticas[estadoActual][cimaPila][caracterLeido]; 
        }
        
        auxCaracter = fgetc(stdin);  // Pasa al siguiente caracter
    }

    if((eLectura.actualStatus == Q1 || eLectura.actualStatus == Q2) && topePila(stack) == SignoPeso)
        puts("Es sintacticamente correcto.");
    else
        puts("No es sintacticamente correcto.");

    char option;

    printf("Desea volver a compilar el programa? (S/N): ");
    
    if(option == 's' || option == 'S')
        main();

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

void initStack(Node** stack)
{
    pushStack(stack, '$');
}
 
void showStack(Node* stack)
{
    Node* p = (Node*) malloc(sizeof(Node));
    p = stack;
    printf("Stack: ");
    if(stack != NULL)
    {
        while(p != NULL)
        {
            printf("%c", p->data);
            p = p->next;
            if(p != NULL)
                printf(" -> ");
        }
        puts("");
    }
    else
        puts("La pila esta vacia");
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
        return RInStack;
    else
        return SignoPeso;
}