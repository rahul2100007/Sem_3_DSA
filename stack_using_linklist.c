//stack using linklist in c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int isEmpty(struct Node* root) {
    return !root;
}

void push(struct Node** root, int data) {
    struct Node* node = newNode(data);
    node->next = *root;
    *root = node;
    printf("%d pushed to stack\n", data);
}

int pop(struct Node** root) {
    if (isEmpty(*root))
        return -1;
    struct Node* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

int peek(struct Node* root) {
    if (isEmpty(root))
        return -1;
    return root->data;
}

void display(struct Node* root) {
    struct Node* temp = root;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);

    printf("Stack elements: ");
    display(root);

    printf("%d popped from stack\n", pop(&root));
    printf("Top element is %d\n", peek(root));

    printf("Stack elements after pop: ");
    display(root);

    return 0;
}




