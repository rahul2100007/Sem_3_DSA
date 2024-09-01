#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_length 1000
#define stack_size 1000

char undoStack[stack_size][max_length];
char redoStack[stack_size][max_length];
int undoTop = -1;
int redoTop = -1;

void push_undo(char* text);
void push_redo(char* text);
void pop_undo(char* text);
void pop_redo(char* text);
void textEditor();

void push_undo(char* text) {
    if (undoTop < stack_size - 1) {
        strcpy(undoStack[++undoTop], text);
    }
}

void push_redo(char* text) {
    if (redoTop < stack_size - 1) {
        strcpy(redoStack[++redoTop], text);
    }
}

void pop_undo(char* text) {
    if (undoTop >= 0) {
        strcpy(text, undoStack[undoTop--]);
    }
}

void pop_redo(char* text) {
    if (redoTop >= 0) {
        strcpy(text, redoStack[redoTop--]);
    }
}

void textEditor() {
    char text[max_length];

    while (1) {
        printf("Text:%s\n",text);
        printf("Options:\n");
        printf("1. Append text\n");
        printf("2. Undo\n");
        printf("3. Redo\n");
        printf("4. Exit\n");

        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char newText[max_length];
                printf("Enter text to append: ");
                scanf(" %[^\n]s", newText);
                push_undo(text);
                strcat(text, newText);
                redoTop = -1;
                break;
            }
            case 2: {
                if (undoTop >= 0) {
                    push_redo(text);
                    pop_undo(text);
                }
                break;
            }
            case 3: {
                if (redoTop >= 0) {
                    push_undo(text);
                    pop_redo(text);
                }
                break;
            }
            case 4:
                exit(0);
            default: {
                printf("Invalid choice.\n");
            }
        }
    }
}

int main() {
    textEditor();
    return 0;
}