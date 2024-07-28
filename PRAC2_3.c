#include <stdio.h>

int main()
{
    int number, digits[5];

    printf("Enter a five-digit number: ");
    scanf("%d", &number);

    for (int i = 4; i >= 0; i--)
    {
        digits[i] = number % 10;
        number /= 10;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d", digits[i]);
        if (i < 4)
        {
            printf("   ");
        }
    }
    printf("\n");

    return 0;
}