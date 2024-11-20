#include <stdio.h>
int i, j, k;
void selectionSort(int arr[], int n)
{
    for (i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
        printf("[");
        for (k = 0; k < n; k++)
        {
            printf("%d", arr[k]);
            if (k < n - 1)
            {
                printf(", ");
            }
        }
        printf("]\n");
    }
}
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nStep-by-Step Sorting Process:\n");
    selectionSort(arr, n);
    printf("\nFinal Sorted Array:\n[");
    for (i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i < n - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
    return 0;
}
