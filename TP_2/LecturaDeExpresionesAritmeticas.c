#include <stdio.h>
#include <stdlib.h>

enum{Zero, To1_9, Operators, ParenthesesOpen, ParenthesesClose}; // Números asociados a los caracteres leídos
enum{Init, ReadedNumberOrSymbol, Parentheses, NoExp};            // Nombres de Estados
enum{Empty, RInStack, Epsilon};                                  // Nombres asignados a valores de la pila
//    '$'      'R'    Epsilon

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
void insertParenthesesToStack(Node**);  // Agrega a pila el caracter 'R'
void showStack(Node*);                  // Muestra el contenido de pila (No lo usamos)
short columnPosition(char);             // Dependiendo el caracter que lee, decide asignar un número específico
StatStack fillStruct(short, short);     // Rellena el struct dependiendo el estado

int main()
{
    Node* stack = NULL;
    initStack(&stack); 

    StatStack AFPExpresionesAritmeticas[4][2][5] =  // [Estado Actual] [Cima de Pila] [Caracter Leido]
        {
            {  //Initialization         // Q0
                {   //Empty     // '$'
                    fillStruct(NoExp, Empty),                   //   -  , '$' -> -
                    fillStruct(ReadedNumberOrSymbol, Empty),    //  Q1  , '$'
                    fillStruct(NoExp, Empty),                   //   -  , '$' -> -
                    fillStruct(Init, RInStack),                 //  Q0  , 'R'
                    fillStruct(NoExp, Empty)                    //   -  , '$' -> -
                },
                {   //RInStack  // 'R'
                    fillStruct(NoExp, RInStack),                // -  ,  'R' -> -
                    fillStruct(ReadedNumberOrSymbol, RInStack), // 
                    fillStruct(NoExp, RInStack),
                    fillStruct(Init, RInStack),
                    fillStruct(NoExp, RInStack)
                }  
            },
            {   //ReadedNumberOrSymbol  
                {   //Empty
                    fillStruct(ReadedNumberOrSymbol, Empty),
                    fillStruct(ReadedNumberOrSymbol, Empty),
                    fillStruct(Init, Empty),
                    fillStruct(NoExp, Empty),
                    fillStruct(NoExp, Empty)
                },
                {   //RInStack
                    fillStruct(ReadedNumberOrSymbol, RInStack),
                    fillStruct(ReadedNumberOrSymbol, RInStack),
                    fillStruct(Init, RInStack),
                    fillStruct(NoExp, RInStack),
                    fillStruct(Parentheses, Epsilon)
                }  
            }
            ,
            {   //Parentheses
                {   //Empty
                    fillStruct(NoExp, Empty),
                    fillStruct(NoExp, Empty),
                    fillStruct(Init, Empty),
                    fillStruct(NoExp, Empty),
                    fillStruct(NoExp, Empty)
                }, 
                {   //RInStack
                    fillStruct(NoExp, RInStack),
                    fillStruct(NoExp, RInStack),
                    fillStruct(Init, RInStack),
                    fillStruct(NoExp, RInStack),
                    fillStruct(Parentheses, Epsilon)
                }
            },
            {   //No Expression
                {   //Empty
                    fillStruct(NoExp, Empty),
                    fillStruct(NoExp, Empty),
                    fillStruct(NoExp, Empty),
                    fillStruct(NoExp, Empty),
                    fillStruct(NoExp, Empty)
                },
                {   //RInStack
                    fillStruct(NoExp, RInStack),
                    fillStruct(NoExp, RInStack),
                    fillStruct(NoExp, RInStack),
                    fillStruct(NoExp, RInStack),
                    fillStruct(NoExp, RInStack)
                }  
            }
        };

    puts("Ingrese una expresion aritmetica:");
    char auxCaracter = fgetc(stdin); // Lee y elimina caracteres de la expresion

    while(auxCaracter != '\n')       // Mientras no haya terminado
    {
        if(auxCaracter != ' ')       // Saltear espacios
        {
            /*

            CODIGO

            */
        }
        
        auxCaracter = fgetc(stdin);  // Pasa al siguiente caracter
    }

    return 0;                        // Termina el programa
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

    printf("\'%c\' agregado a pila.\n", data);
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

void insertParenthesesToStack(Node** stack)
{
    pushStack(stack, 'R');
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
    else if(letter >= 1 && letter <= 9)
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