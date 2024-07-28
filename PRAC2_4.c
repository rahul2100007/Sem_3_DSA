#include <stdio.h>
int main()
{
    int rows = 5;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if (i > 0 && i < rows - 1 && j > 0 && j < rows - 1)
            {
                printf("  ");
            }
            else
            {
                printf("* ");
            }
        }
        printf("\n");
    }

    int n = 5;

    for (int i = 0; i < 2 * n - 1; i++)
    {
        int comp;
        if (i < n)
        {
            comp = 2 * (n - i) - 1;
        }
        else
        {
            comp = 2 * (i - n + 1) + 1;
        }

        for (int j = 0; j < comp; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < 2 * n - comp; k++)
        {
            if (k == 0 || k == 2 * n - comp - 1)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    int rows_1 = 5;

    for (int i = 0; i < rows_1; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}
