
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int college_ID;
    char College_name[50];
    struct Node *prev;
    struct Node *next;
};

void print(struct Node *head) {
    struct Node *ptr = head;
    printf("=============OUTPUT OF STUDENT DATA==============\n");
    printf("college_ID\tCollege_name\n");
    while (ptr != NULL) {
        printf("%d\t\t %s\n", ptr->college_ID, ptr->College_name);
        ptr = ptr->next;
    }
}

struct Node *create(struct Node *head) {
    int num_stu;
    printf("Enter how many data you want to add: ");
    scanf("%d", &num_stu);
    struct Node *temp = head;
    printf("=============ENTER DATA==============\n");
    printf("college_ID\tCollege_name\n");
    for (int i = 0; i < num_stu; i++) {
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            exit(0);
        }
        printf("Enter college data %d:\n", i + 1);
        scanf("%d %s", &newnode->college_ID, newnode->College_name);

        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
        }
        temp = head;
    }
    return head;
}

struct Node *search_record(struct Node *head) {
    struct Node *ptr = head;
    int id;
    char name[50];
    int choice;
    printf("Enter your choice: search by ID or search by name\n <1> for by ID <2> for by name: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter ID: ");
            scanf("%d", &id);
            while (ptr != NULL && ptr->college_ID != id) {
                ptr = ptr->next;
            }
            if (ptr == NULL) {
                printf("Record not found :(\n");
            } else {
                printf("%d %s\n", ptr->college_ID, ptr->College_name);
            }
            break;
        case 2:
            printf("Enter name: ");
            scanf("%s", name);
            while (ptr != NULL && strcmp(ptr->College_name, name) != 0) {
                ptr = ptr->next;
            }
            if (ptr == NULL) {
                printf("Record not found :(\n");
            } else {
                printf("%d %s\n", ptr->college_ID, ptr->College_name);
            }
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    return head;
}

int main() {
    int choice;
    struct Node *head = NULL;
    head = create(head);
    do {
        printf("Enter choice: 1 for display, 2 for add data, 3 for search record, 0 for exit: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                print(head);
                break;
            case 2:
                head = create(head);
                break;
            case 3:
                search_record(head);
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 0);
    return 0;
}