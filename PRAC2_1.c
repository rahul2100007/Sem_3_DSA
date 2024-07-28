#include <stdio.h>

int sum(int a, int b) {
    return a + b;
}

int product(int a, int b) {
    return a * b;
}

int difference(int a, int b) {
    return a - b;
}

int quotient(int a, int b) {
    return a / b;
}

int modulus(int a, int b) {
    return a % b;
}

int main() {
    int num1, num2, choice;
    char continue_choice;

    do {
        printf("Choose an operation:\n");
        printf("1. Sum\n");
        printf("2. Product\n");
        printf("3. Difference\n");
        printf("4. Quotient\n");
        printf("5. Remainder\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("Enter the first number: ");
        scanf("%d", &num1);
        printf("Enter the second number: ");
        scanf("%d", &num2);

        switch (choice) {
            case 1:
                printf("Sum: %d\n", sum(num1, num2));
                break;
            case 2:
                printf("Product: %d\n", product(num1, num2));
                break;
            case 3:
                printf("Difference: %d\n", difference(num1, num2));
                break;
            case 4:
                printf("Quotient: %d\n", quotient(num1, num2));
                break;
            case 5:
                printf("Remainder: %d\n", modulus(num1, num2));
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

        printf("Do you want to perform another operation? (y/n): ");
        scanf(" %c", &continue_choice);
    } while (continue_choice == 'y' || continue_choice == 'Y');

    return 0;
}