#include <stdio.h>
int i, j, k;
void bubbleSort(int arr[], int n)
{
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        printf("Iteration %d:\n[", i + 1);
        for (k = 0; k < n; k++)
        {
            printf("%d", arr[k]);
            if (k < n - 1)
            {
                printf(",");
            }
        }
        printf("]\n\n");
    }
}
int main()
{
    int truck_weights[] = {40, 10, 30, 50, 20};
    int n = sizeof(truck_weights) / sizeof(truck_weights[0]);
    printf("Initial Array:\n[");
    for (i = 0; i < n; i++)
    {
        printf("%d", truck_weights[i]);
        if (i < n - 1)
        {
            printf(",");
        }
    }
    printf("]\n\n");
    bubbleSort(truck_weights, n);
    printf("Final Sorted Array:\n[");
    for (i = 0; i < n; i++)
    {
        printf("%d", truck_weights[i]);
        if (i < n - 1)
        {
            printf(",");
        }
    }
    printf("]\n");
    return 0;
}