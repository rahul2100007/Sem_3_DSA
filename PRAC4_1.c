#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char infix_eq[100];
char postfix_eq[100];
char stack[100];
int top = -1;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

char peek() {
    if (top == -1) return -1;
    return stack[top];
}

int size_of(char xyz[]) {
    int y = 0;
    int cnt = 0;
    while (xyz[y] != '\0') {
        cnt++;
        y++;
    }
    return cnt;
}

void infix_to_postfix() {
    printf("ENTER EXPRESSION: ");
    int l = 0;
    char ch;
    while ((ch = getchar()) != ';') {
        infix_eq[l++] = ch;
    }
    infix_eq[l] = '\0';

    int k = 0;
    for (int i = 0; i < strlen(infix_eq); i++) {
        if ((infix_eq[i] >= 'a' && infix_eq[i] <= 'z') || (infix_eq[i] >= 'A' && infix_eq[i] <= 'Z')) {
            postfix_eq[k++] = infix_eq[i];
        } else if (infix_eq[i] == '(') {
            push(infix_eq[i]);
        } else if (infix_eq[i] == ')') {
            while (peek() != '(') {
                postfix_eq[k++] = pop();
            }
            pop();
        } else {
            while (top != -1 && precedence(peek()) >= precedence(infix_eq[i])) {
                postfix_eq[k++] = pop();
            }
            push(infix_eq[i]);
        }
    }

    while (top != -1) {
        postfix_eq[k++] = pop();
    }

    postfix_eq[k] = '\0';
}

int main() {
    infix_to_postfix();
    printf("Postfix Expression: %s\n", postfix_eq);
    return 0;
}