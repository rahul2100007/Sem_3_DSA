#include <stdio.h>

int main() {
    int number, new_number = 0, place = 1;
    
    printf("Enter a five-digit number: ");
    scanf("%d", &number);
    
    for (int i = 0; i < 5; i++) {
        int digit = number % 10;  
        number /= 10;             
        
        digit = (digit == 0) ? 9 : digit - 1;
        
        new_number += digit * place;
        place *= 10;
    }
    printf("New number: %05d\n", new_number);
    
    return 0;
}