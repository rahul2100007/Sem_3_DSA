#include <stdio.h>
#include <stdlib.h>

int i_ball[9];
int size_basket = 0;

int ball_push(int a)
{
    int ball;
    while (1)
    {
        printf("Enter ball number: ");
        scanf("%d", &ball);
        int exists = 0;
        for (int k = 0; k < size_basket; k++)
        {
            if (ball == i_ball[k])
            {
                printf("Ball already exists\n");
                exists = 1;
                break;
            }
        }
        if (!exists)
        {
            i_ball[size_basket] = ball;
            size_basket++;
            break;
        }
    }
    return 0;
}

int pop_ball()
{
    if (size_basket > 0)
    {
        size_basket--;
    }
    else
    {
        printf("No balls to pop\n");
    }
    return size_basket;
}

void display()
{
    if (size_basket != 0)
    {
        printf("Total balls in your basket: [ ");
        for (int i = 0; i < size_basket; i++)
        {
            printf("%d ", i_ball[i]);
        }
        printf("]\n");
        printf("Total %d balls in basket :)\n", size_basket);
    }
    else if (size_basket == 0)
    {
        printf("No balls in basket:(\n");
    }
}

int attempt_push()
{
    int x;
    printf("How many balls do you want to throw at this time: ");
    scanf("%d", &x);
    if (x > 9 || size_basket + x > 9)
    {
        printf("You can't throw more than 9 balls because it has no space greater than '9'\n");
    }
    else
    {
        for (int i = 0; i < x; i++)
        {
            ball_push(size_basket);
        }
    }
    return 0;
}
int attempt_pop()
{
    int x;
    printf("How many balls do you want to pop at this time: ");
    scanf("%d", &x);
    if (x > size_basket)
    {
        printf("You can't pop more balls than you have\n");
    }
    else
    {
        printf("Ball popped\n");
        for (int i = 0; i < x; i++)
        {
            pop_ball();
        }
    }
    return size_basket;
}
int main()
{
    printf("____    __    ____  _______  __        ______   ______   .___  ___.  _______ \n");
    printf("\\   \\  /  \\  /   / |   ____||  |      /      | /  __  \\  |   \\/   | |   ____|\n");
    printf(" \\   \\/    \\/   /  |  |__   |  |     |  ,----'|  |  |  | |  \\  /  | |  |__   \n");
    printf("  \\            /   |   __|  |  |     |  |     |  |  |  | |  |\\/|  | |   __|  \n");
    printf("   \\    /\\    /    |  |____ |  `----.|  `----.|  `--'  | |  |  |  | |  |____ \n");
    printf("    \\__/  \\__/     |_______||_______| \\______| \\______/  |__|  |__| |_______|\n");
    printf("                                                                             \n");
    int choice;
    printf("Welcome to the ball game\n");
    do
    {
        printf("<1> Push\n<2> Pop\n<3> Display Score\n<9> Restart Game\n<0> To exit game\nENTER CHOICE: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            attempt_push();
            break;
        case 2:
            attempt_pop();
            break;
        case 3:
            display();
            break;
        case 9:
            size_basket = 0;
            printf("Game restarted\n");
            break;
        case 0:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 0);
    return 0;
}
