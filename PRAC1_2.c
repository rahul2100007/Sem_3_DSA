#include <stdio.h>

double kmtofeet(int dist)
{
    double feet = dist * 3280.84;
    printf("feet: %.2f\n", feet);
    return 0;
}

double kmtomtr(int dist)
{
    double mtr = dist * 1000.0;
    printf("meters: %.2f\n", mtr);
    return 0;
}

double kmtoinch(int dist)
{
    double inch = dist * 39370.1;
    printf("inches: %.2f\n", inch);
    return 0;
}

double kmtocm(int dist)
{
    double cm = dist * 100000.0;
    printf("centimeters: %.2f\n", cm);
    return 0;
}

int main()
{
    int dist;
    printf("Enter the distance in kilometers: ");
    scanf("%d", &dist);
    kmtofeet(dist);
    kmtomtr(dist);
    kmtoinch(dist);
    kmtocm(dist);
    return 0;
}