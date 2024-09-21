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
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));//Allocate memory for the stack structure
    //sp point to stack structure 
    //this snippet initializes a stack
    sp->size = 20;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));//array for store postfix expression
    int i = 0; // Track infix traversal
    int j = 0; // Track postfix addition

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]) && infix[i] != '(' && infix[i] != ')')//operands are directly push into postfix expression
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
            while (!isEmpty(sp) && stackTop(sp) != '(')//push all the operators while '(' not spotted.
            {
                postfix[j] = pop(sp);
                j++;
            }
            if (!isEmpty(sp) && stackTop(sp) != '(')//this condition indicate invalid equation because ')' spotted without start '('.
            {
                return NULL; // Invalid expression
            }
            else
            {
                pop(sp);
            }
            i++;
        }
        else
        {
            while (!isEmpty(sp) && precedence(infix[i]) <= precedence(stackTop(sp)))//if operator spotted
            {
                postfix[j] = pop(sp);//precedence is greater then upcoming operator thats why pop top operator and push it into postfix
                j++;
            }
            push(sp, infix[i]);//precendence is greater then top element that's why operator push in to stack
            i++;
        }
    }

    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);//pop and push remaining operator from stack to postfix
        j++;
    }
    postfix[j] = '\0';//at last of postfix expression assign NULL 
    free(sp);
    free(sp->arr);
    return postfix;
}

int main()
{
    char* infix;
    printf("Enter the infix expression\n");
    gets(infix);
    printf("Postfix is %s\n", infixToPostfix(infix));
    return 0;
}