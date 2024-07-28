#include <stdio.h>

int main()
{
    float selling_price, profit, cost_price, cost_price_per_item;

    printf("Enter the total selling price of 15 items: ");
    scanf("%f", &selling_price);

    printf("Enter the total profit earned: ");
    scanf("%f", &profit);

    cost_price = selling_price - profit;
    cost_price_per_item = cost_price / 15;

    printf("The cost price of one item is: %.2f\n", cost_price_per_item);

    return 0;
}