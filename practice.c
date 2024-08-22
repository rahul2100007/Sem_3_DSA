#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define max_size 100

char stack[max_size];
int top = -1;
bool stackOverflow = false;

void pushStack(char data);
char popStack(void);
char stackTop(void);
bool emptyStack(void);
int precedence(char ch);
bool isOperator(char ch);
bool isOperand(char ch);
void reverseString(char* str);
void replaceParentheses(char* str);

void pushStack(char data) {
    if (top < max_size - 1) {
        stack[++top] = data;
    } else {
        stackOverflow = true;
    }
}

char popStack(void) {
    if (emptyStack()) {
        return '\0';
    }
    return stack[top--];
}

char stackTop(void) {
    if (emptyStack()) {
        return '\0';
    }
    return stack[top];
}

bool emptyStack(void) {
    return top == -1;
}

int precedence(char ch) {
    if (ch == '^') {
        return 3;
    }
    if (ch == '*' || ch == '/') {
        return 2;
    }
    if (ch == '+' || ch == '-') {
        return 1;
    }
    return 0;
}

bool isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

bool isOperator(char ch) {
    return ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-';
}

void reverseString(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void replaceParentheses(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(') {
            str[i] = ')';
        } else if (str[i] == ')') {
            str[i] = '(';
        }
    }
}

int main(void) {
    char infix[max_size];
    char postfix[max_size] = "";
    char prefix[max_size] = "";
    char temp[2];
    char ch;

    printf("Enter an infix formula: ");
    fgets(infix, max_size, stdin);
    infix[strcspn(infix, "\n")] = '\0';

    reverseString(infix);
    replaceParentheses(infix);

    for (int i = 0; i < strlen(infix); i++) {
        ch = infix[i];
        if (ch == '(') {
            pushStack(ch);
        } else if (ch == ')') {
            char data = popStack();
            while (data != '(') {
                temp[0] = data;
                temp[1] = '\0';
                strcat(postfix, temp);
                data = popStack();
            }
        } else if (isOperator(ch)) {
            while (!emptyStack() && precedence(ch) <= precedence(stackTop())) {
                char data = popStack();
                temp[0] = data;
                temp[1] = '\0';
                strcat(postfix, temp);
            }
            pushStack(ch);
        } else if (isOperand(ch)) {
            temp[0] = ch;
            temp[1] = '\0';
            strcat(postfix, temp);
        }
    }

    while (!emptyStack()) {
        char data = popStack();
        temp[0] = data;
        temp[1] = '\0';
        strcat(postfix, temp);
    }

    reverseString(postfix);
    strcpy(prefix, postfix);

    if (stackOverflow) {
        printf("Error: Stack overflow\n");
    } else {
        printf("The prefix formula is: %s\n", prefix);
    }

    return 0;
}