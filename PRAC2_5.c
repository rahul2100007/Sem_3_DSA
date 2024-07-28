#include <stdio.h>

#define PI 3.14159

double diameter(double radius)
{
    return 2 * radius;
}

double circumference(double radius)
{
    return 2 * PI * radius;
}

double area(double radius)
{
    return PI * radius * radius;
}

int main()
{
    double radius;

    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);

    printf("Diameter: %.2f\n", diameter(radius));
    printf("Circumference: %.2f\n", circumference(radius));
    printf("Area: %.2f\n", area(radius));

    return 0;
}