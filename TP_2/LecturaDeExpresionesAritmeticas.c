#include <stdio.h>
#include <stdlib.h>

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
char peekStack(Node*);
char popStack(Node**);
void initStack(Node**);
void insertParenthesesToStack(Node**);
void showStack(Node*);
short columnPosition(char);
StatStack fillStruct(short, short);

int main()
{
    Node* stack = NULL;
    initStack(&stack); 
    insertParenthesesToStack(&stack);
    insertParenthesesToStack(&stack);
    insertParenthesesToStack(&stack);
    showStack(stack);
    while (stack != NULL)
        printf("La cima de pila es: %c \n", popStack(&stack));
 
    //printf("%c", stackOut(stack));
    //printf("Hello World!");

    /* StatStack AFPExpresionesAritmeticas[4][2][5] =
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
        };  */

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