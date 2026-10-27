#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
char s[MAX];
int Top = -1;
char infix[MAX], postfix[MAX];

void intopos();
void push(char symbol);
char pop();
int isEmpty();
int precedence(char symbol);
void display();

int main()
{
    printf("enter the infix expression :\n");
    gets(infix);
    intopos();
    display();
    return 0;
}

void intopos()
{
    int i, j = 0;
    char symbol, next;
    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        switch (symbol)
        {
        case '(':
            push(symbol);
            break;
        case ')':
            while ((next = pop()) != '(')
            {
                postfix[j++] = next;
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while (!isEmpty() && precedence(s[Top]) >= precedence(symbol))
            {
                postfix[j++] = pop();
            }
            push(symbol);
            break;
        default:
            postfix[j++] = symbol;
        }
    }
    while (!isEmpty())
    {
        char leftover = pop();
        if (leftover == '(')
        {
            printf("Invalid parentheses");
            exit(1);
        }
        postfix[j++] = leftover;
    }
    postfix[j] = '\0';
}

int isEmpty()
{
    if (Top == -1)
    {
        return 1;
    }
    return 0;
}

void push(char symbol)
{
    if (Top == MAX - 1)
    {
        printf("Stack overflow\n");
        exit(1);
    }
    else
    {
        Top++;
        s[Top] = symbol;
    }
}

char pop()
{
    if (isEmpty())
    {
        printf("Stack underflow\n");
        exit(1);
    }
    else
    {
        int c = s[Top];
        Top--;
        return c;
    }
}

int precedence(char symbol)
{
    switch (symbol)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

void display()
{
    int i = 0;
    printf("Equivalent postfix expression is: ");
    while (postfix[i])
    {
        printf("%c", postfix[i++]);
    }
    printf("\n");
}
