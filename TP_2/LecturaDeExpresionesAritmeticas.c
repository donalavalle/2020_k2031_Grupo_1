#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

enum{Zero, To1_9, Operators, ParenthesesOpen, ParenthesesClose};
enum{Init, ReadedNumberOrSymbol, Parentheses, NoExp};
enum{Empty, RInStack, Epsilon};

typedef struct node
{
    char data;
    struct node* next;
} Node;

typedef struct status_topStack
{
    short actualStatus;
    short topStack;
} StatStack;

Node* newNode(char);
void pushStack(Node**, char);
short peekStack(Node*);
char popStack(Node**);
short setValueByTop(Node**);
void initStack(Node**);
void insertByValue(Node**, short);
void showStack(Node*);
short charPosition(char);
StatStack fillStruct(short, short);

int main()
{
    char auxLectura;

    Node* stack = NULL;
    initStack(&stack); 

    StatStack eActual = {Init, Empty};  //Seteo Estado Inicial

    StatStack AFPExpresionesAritmeticas[4][2][5] =  // [Estado Actual] [Cima de Pila] [Caracter Leído]
        {
            {  //Initialization
                {   //Empty
                    fillStruct(NoExp, Empty),
                    fillStruct(ReadedNumberOrSymbol, Empty),
                    fillStruct(NoExp, Empty),
                    fillStruct(Init, RInStack),
                    fillStruct(NoExp, Empty)
                },
                {   //RInStack
                    fillStruct(NoExp, RInStack),
                    fillStruct(ReadedNumberOrSymbol, RInStack),
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
                {
                    fillStruct(NoExp, RInStack),
                    fillStruct(NoExp, RInStack),
                    fillStruct(NoExp, RInStack),
                    fillStruct(NoExp, RInStack),
                    fillStruct(NoExp, RInStack)
                }  //RInStack
            }
        }; 

    printf("Ingrese una expresi%cn aritm%ctica: \n", 162, 130);
    fflush(stdin);

    short posChar;

    auxLectura = fgetc(stdin);
    while(auxLectura != '\n')
    {
        if(auxLectura != ' ')
        {   
            //printf("\nChar leido: %c\n", auxLectura);

            posChar = charPosition(auxLectura);
            short auxPop = setValueByTop(&stack);

            //printf("Pop de Pila: %d\n", auxPop);
            //printf("Estado: %d\tPila: %d\tChar: %d\n", eActual.actualStatus, eActual.topStack, posChar);
            eActual = AFPExpresionesAritmeticas[eActual.actualStatus][eActual.topStack][posChar];
            //printf("Estado: %d\tPila: %d\n", eActual.actualStatus, eActual.topStack);

            if(auxPop == Empty && eActual.topStack == RInStack)
            {
                insertByValue(&stack, auxPop);
                insertByValue(&stack, eActual.topStack);
            }
            else if (auxPop == RInStack && posChar == ParenthesesOpen)
            {
                insertByValue(&stack, auxPop);
                insertByValue(&stack, eActual.topStack);
            }
            else if(eActual.topStack != Epsilon)
                insertByValue(&stack, auxPop);
            else if(eActual.topStack == Epsilon)
                eActual.topStack = peekStack(stack);
            //puts("");
            //showStack(stack);
            
            auxLectura = fgetc(stdin);
        }
        else
            auxLectura = fgetc(stdin);
    }

    if(eActual.actualStatus == NoExp || posChar == Operators || peekStack(stack) == RInStack)
        printf("No es sint%ccticamente correcta.\n", 160);
    else
        printf("Es sint%ccticamente correcta.\n", 160);

    char option;

    printf("%cDesea volver a realizar el programa? (S/N): ", 168);
    scanf("%c", &option);

    if(toupper(option) == 'S')
        main();

    return 0;
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

short peekStack(Node* p)
{
    if(p != NULL)
    {
        if(p->data == 'R')
            return RInStack;
        else
            return Empty;
    }
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

short setValueByTop(Node** stack)
{
    char auxPop = popStack(stack);

    if(auxPop == 'R')
        return RInStack;
    else
        return Empty;
}

void insertByValue(Node** stack, short t)
{
    if(t == Empty)
        pushStack(stack, '$');
    else
        pushStack(stack, 'R');
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

short charPosition(char letter)
{
    short posChar;

    if(letter == '0')
        posChar = Zero;
    else if(letter >= '1' && letter <= '9')
        posChar = To1_9;
    else if(letter == '+' || letter == '-' || letter == '*' || letter == '/')
        posChar = Operators;
    else if(letter == '(')
        posChar = ParenthesesOpen;
    else if(letter == ')')
        posChar = ParenthesesClose;

    return posChar;
}

StatStack fillStruct(short status, short top)
{
    StatStack stat_top;
    stat_top.actualStatus = status;
    stat_top.topStack = top;

    return stat_top;
} 