#include <stdio.h>
#include <string.h>
#define MAX 100
char post[MAX], infix[MAX], s[MAX];
int t = -1;

void push(char x)
{
    if (t == MAX - 1)
    {
        printf("Stack overflow");
        return;
    }
    s[++t] = x;
}

int pop()
{
    if (t == -1)
    {
        printf("Stack underflow");
        return -1;
    }
    return s[t--];
}

void main()
{
    printf("Enter the post exp:\n");
    gets(post);
    char symbol;
    int r = 0;
    for (int i = 0; i < strlen(post); i++)
    {
        symbol = post[i];
        if (symbol >= '0' && symbol <= '9')
        {
            push(symbol - '0');
        }
        else
        {
            int y = pop();
            int x = pop();
            switch (symbol)
            {
            case '+':
                r = x + y;
                break;
            case '-':
                r = x - y;
                break;
            case '*':
                r = x * y;
                break;
            case '/':
                if (y == 0)
                {
                    printf("Division by zero error");
                    return;
                }
                r = x / y;
                break;
            }
            push(r);
        }
    }
    printf("The result is : %d", pop());
}
