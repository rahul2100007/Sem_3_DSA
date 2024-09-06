#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node* insertvalue(struct node *first, int data) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = NULL;

    if (first == NULL) {
        first = ptr;
    } else {
        struct node *temp = first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
    }
    return first;
}

void print(struct node *ptr) {
    printf("NULL -> ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}

int main() {
    struct node *first = NULL;
    for (int i = 0; i < 3; i++) {
        int x;
        printf("Enter a number: ");
        scanf("%d", &x);
        first = insertvalue(first, x);
    }
    print(first);
    return 0;
}