#include <stdio.h>
#include <stdlib.h>

enum{Zero, To1_9, Operators, ParenthesesOpen, ParenthesesClose};
enum{Init, ReadedNumberOrSymbol, Parentheses, NoExp};
enum{Empty, PutLetterRInStack, Epsilon};

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

/* void deleteNode(Node*);
void stackIn(Node*, char);
char stackOut(Node*);
void initStack(Stack*);
void insertParenthesesToStack(Stack*);
void showStack(Node*); */
short columnPosition(char);
StatStack fillStruct(short, short);

int main()
{
    StatStack AFPExpresionesAritmeticas[4][2][5] =
        {
            {  //Initialization
                {   //Empty
                    fillStruct(NoExp, Empty),
                    fillStruct(ReadedNumberOrSymbol, Empty),
                    fillStruct(NoExp, Empty),
                    fillStruct(Init, PutLetterRInStack),
                    fillStruct(NoExp, Empty)
                },
                {   //putLetterRInStack
                    fillStruct(NoExp, PutLetterRInStack),
                    fillStruct(ReadedNumberOrSymbol, PutLetterRInStack),
                    fillStruct(NoExp, PutLetterRInStack),
                    fillStruct(Init, PutLetterRInStack),
                    fillStruct(NoExp, PutLetterRInStack)
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
                {   //putLetterRInStack
                    fillStruct(ReadedNumberOrSymbol, PutLetterRInStack),
                    fillStruct(ReadedNumberOrSymbol, PutLetterRInStack),
                    fillStruct(Init, PutLetterRInStack),
                    fillStruct(NoExp, PutLetterRInStack),
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
                {   //putLetterRInStack
                    fillStruct(NoExp, PutLetterRInStack),
                    fillStruct(NoExp, PutLetterRInStack),
                    fillStruct(Init, PutLetterRInStack),
                    fillStruct(NoExp, PutLetterRInStack),
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
                    fillStruct(NoExp, PutLetterRInStack),
                    fillStruct(NoExp, PutLetterRInStack),
                    fillStruct(NoExp, PutLetterRInStack),
                    fillStruct(NoExp, PutLetterRInStack),
                    fillStruct(NoExp, PutLetterRInStack)
                }  //putLetterRInStack
            }
        }; 

    return 0;
}

/* void deleteNode(Node* p)
{
    p->next = NULL;
    free(p);
}

void stackIn(Node* stack, char letter)
{
    Node* newNode= (Node*) malloc(sizeof(Node));
    newNode->data = letter;
    newNode->next = stack;
    stack = newNode;
    printf("Dato agregado: %c\n", stack->data);
}

char stackOut(Node* stack)
{   
    if(stack != NULL)
    {
        char letter;
        
        Node* p = stack;
        letter = p->data;
        stack = p->next;
        deleteNode(p);

        return letter;
    }

}

void initStack(Stack* stack)
{
    stackIn(stack, '$');
}

void insertParenthesesToStack(Stack*stack)
{
    stackIn(stack, 'R');
} 

void showStack(Node* stack)
{
    Node* p = (Node*) malloc(sizeof(Node));
    p = stack;
    puts("Stack: ");
    if(stack != NULL)
    {
        while(p != NULL)
        {
            printf(" -> %c ", p->data);
            p = p->next;
        }
    }
    else
        puts("La pila esta vacia");
}*/

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