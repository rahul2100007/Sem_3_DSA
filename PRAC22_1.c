#include <stdio.h>
int linearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}
int binarySearch(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int unsortedArr[] = {34, 7, 23, 32, 5, 62, 42};
    int sortedArr[] = {5, 7, 23, 32, 34, 42, 62};
    int size = sizeof(unsortedArr) / sizeof(unsortedArr[0]);
    int target = 42;
    int linearResult = linearSearch(unsortedArr, size, target);
    if (linearResult != -1)
    {
        printf("Linear Search: Element found at index %d\n", linearResult);
    }
    else
    {
        printf("Linear Search: Element not found\n");
    }
    int binaryResult = binarySearch(sortedArr, size, target);
    if (binaryResult != -1)
    {
        printf("Binary Search: Element found at index %d\n", binaryResult);
    }
    else
    {
        printf("Binary Search: Element not found\n");
    }
    return 0;
}
