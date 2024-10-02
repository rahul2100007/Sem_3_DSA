#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

int isEmpty(struct stack *ptr)
{
    return ptr->top == -1;
}

int isFull(struct stack *ptr)
{
    return ptr->top == ptr->size - 1;
}

void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %c to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

int isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

char *infixToPostfix(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 20;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]) && infix[i] != '(' && infix[i] != ')')
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else if (infix[i] == '(')
        {
            push(sp, infix[i]);
            i++;
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty(sp) && stackTop(sp) != '(')
            {
                postfix[j] = pop(sp);
                j++;
            }
            if (!isEmpty(sp) && stackTop(sp) != '(')
            {
                return NULL;
            }
            else
            {
                pop(sp);
            }
            i++;
        }
        else
        {
            while (!isEmpty(sp) && precedence(infix[i]) <= precedence(stackTop(sp)))
            {
                postfix[j] = pop(sp);
                j++;
            }
            push(sp, infix[i]);
            i++;
        }
    }

    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    free(sp);
    free(sp->arr);
    return postfix;
}

void reverseString(char *str)
{
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++)
    {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void replaceParentheses(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(')
        {
            str[i] = ')';
        }
        else if (str[i] == ')')
        {
            str[i] = '(';
        }
    }
}

char *infixToPrefix(char *infix)
{
    reverseString(infix);
    replaceParentheses(infix);
    char *postfix = infixToPostfix(infix);
    reverseString(postfix);
    return postfix;
}

int main()
{
    char infix[100];
    printf("Enter the infix expression\n");
    gets(infix);
    printf("Prefix is %s\n", infixToPrefix(infix));
    return 0;
}