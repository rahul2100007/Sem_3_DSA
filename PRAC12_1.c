#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void printMatrix(int **matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int **generateMatrix(int m, int n, struct Node *head)
{
    int **matrix = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }
    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            if (head == NULL)
            {
                matrix[top][i] = -1;
            }
            else
            {
                matrix[top][i] = head->data;
                head = head->next;
            }
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            if (head == NULL)
            {
                matrix[i][right] = -1;
            }
            else
            {
                matrix[i][right] = head->data;
                head = head->next;
            }
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                if (head == NULL)
                {
                    matrix[bottom][i] = -1;
                }
                else
                {
                    matrix[bottom][i] = head->data;
                    head = head->next;
                }
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                if (head == NULL)
                {
                    matrix[i][left] = -1;
                }
                else
                {
                    matrix[i][left] = head->data;
                    head = head->next;
                }
            }
            left++;
        }
    }
    return matrix;
}
int main()
{
    int m, n;
    printf("Enter the dimensions of the matrix (m n): ");
    scanf("%d %d", &m, &n);
    struct Node *head = NULL;
    struct Node *tail = NULL;
    int value;
    printf("Enter the values for the linked list (enter -1 to stop): ");
    while (1)
    {
        scanf("%d", &value);
        if (value == -1)
        {
            break;
        }
        struct Node *newNode = createNode(value);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    int **matrix = generateMatrix(m, n, head);
    printMatrix(matrix, m, n);
    for (int i = 0; i < m; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    while (head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}