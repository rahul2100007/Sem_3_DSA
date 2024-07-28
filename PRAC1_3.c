#include <stdio.h>
int main(){
    float marks[5];
    printf("enter PHYSICS MARKS:");
    scanf("%f", &marks[0]);
    printf("enter CHEMISTRY MARKS:");
    scanf("%f", &marks[1]);
    printf("enter MATHS MARKS:");
    scanf("%f", &marks[2]);
    printf("enter ENGLISH MARKS:");
    scanf("%f", &marks[3]);
    printf("enter COMPUTER SCIENCE MARKS:");
    scanf("%f", &marks[4]);
    float total = marks[0] + marks[1] + marks[2] + marks[3] + marks[4];
    float percentage = (total / 500) * 100;
    printf("The total marks obtained by the student is: %f\n", total);
    printf("The percentage of the student is: %f\n", percentage);
    return 0;
}