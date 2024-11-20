#include <stdio.h>
int i, j, k;
void insertionSort(int arr[], int n)
{
    for (i = 1; i < n; i++)
    {
        int temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
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
    insertionSort(arr, n);
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
