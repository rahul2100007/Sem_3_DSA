#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define max_size 100

char stack[max_size];
int top = -1;
bool satckOflow = false;

void pushStack(char data);
char popStack(void);
char stackTop(void);
bool emptyStack(void);
int precedence(char ch);
bool isOperator(char ch);

void pushStack(char data)
{
    if (top < max_size - 1)
    {
        stack[++top] = data;
    }
    else
    {
        satckOflow = true;
    }
}

char popStack(void)
{
    if (emptyStack())
    {
        return '\0';
    }
    return stack[top--];
}

char stackTop(void)
{
    if (emptyStack())
    {
        return '\0';
    }
    return stack[top];
}

bool emptyStack(void)
{
    return top == -1;
}

int precedence(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    if (ch == '*' || ch == '/')
    {
        return 2;
    }
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    return 0;
}
bool isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}
bool isOperator(char ch)
{
    return ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-';
}

int main(void)
{
    char postfix[100] = "";
    char temp[2] = "";
    char ch;

    printf("Enter an infix formula: ");
    while ((ch = getchar()) != '\n')
    {
        if (ch == '(')
        {
            pushStack(ch);
        }
        else if (ch == ')')
        {
            char data = popStack();
            while (data != '(')
            {
                temp[0] = data;
                temp[1] = '\0';
                strcat(postfix, temp);
                data = popStack();
            }
        }
        else if (isOperator(ch))
        {
            while (!emptyStack() && precedence(ch) <= precedence(stackTop()))
            {
                char data = popStack();
                temp[0] = data;
                temp[1] = '\0';
                strcat(postfix, temp);
            }
            pushStack(ch);
        }
        else if (isOperand(ch))
        {
            temp[0] = ch;
            temp[1] = '\0';
            strcat(postfix, temp);
        }
    }

    while (!emptyStack())
    {
        char data = popStack();
        temp[0] = data;
        temp[1] = '\0';
        strcat(postfix, temp);
    }

    if (satckOflow)
    {
        printf("Error: Stack overflow\n");
    }
    else
    {
        printf("The postfix formula is: %s\n", postfix);
    }

    return 0;
}