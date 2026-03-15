#include <stdio.h>
#include <math.h>

int per() {

    double sides[3];

    printf("Enter values of the sides of the triangle for calculating its perimeter: ");
    for (int i = 0; i < 3; i++){
        scanf("%lf", &sides[i]);
    }

    double perimeter = 0;

    perimeter = sides[0] + sides[1] + sides[2];

    if ((sides[0] > sides[1]) && (sides[0] > sides[2]))
    {   if ((sides[1] + sides[2] <= sides[0]) || ((sides[0] <= 0) || (sides[1] <= 0) || (sides[2] <= 0)))
        {
            printf("Nonexistent\n");
        }
        if (sides[1] + sides[2] > sides[0])
        {
            printf("Perimeter: %.2lf\n", perimeter);
        }
    }

    if ((sides[1] > sides[0]) && (sides[1] > sides[2]))
    {
        if ((sides[0] + sides[2] <= sides[1]) || ((sides[0] <= 0) || (sides[1] <= 0) || (sides[2] <= 0)))
        {
            printf("Nonexistent\n");
        }
        if (sides[0] + sides[2] > sides[1])
        {
            printf("Perimeter: %.2lf\n", perimeter);
        }
    }

    if ((sides[2] > sides[0]) && (sides[2] > sides[1]))
    {
        if ((sides[0] + sides[1] <= sides[2]) || ((sides[0] <= 0) || (sides[1] <= 0) || (sides[2] <= 0)))
        {
            printf("Nonexistent\n");
        }
        if (sides[0] + sides[1] > sides[2])
        {
            printf("Perimeter: %.2lf\n", perimeter);
        }
    }

    if ((sides[0] == sides[2]) && (sides[0] == sides[1]))
    {
        printf("Perimeter: %.2lf\n", perimeter);
    }

    return 0;
}

int area() {


    double sides[3];

    printf("Enter values of the sides of the triangle for calculating its area: ");
    for (int i = 0; i < 3; i++){
        scanf("%lf", &sides[i]);
    }

    double s = 0;
    double p = 0;

    int a = sides[0];
    int b = sides[1];
    int c = sides[2];

    p = (a+b+c) / 2;
    s = sqrt(p*(p-a)*(p-b)*(p-c));

    if ((sides[0] > sides[1]) && (sides[0] > sides[2]))
    {   if ((sides[1] + sides[2] <= sides[0]) || ((sides[0] <= 0) || (sides[1] <= 0) || (sides[2] <= 0)))
        {
            printf("Nonexistent\n");
        }
        if (sides[1] + sides[2] > sides[0])
        {
            printf("Area: %.2lf\n", s);
        }
    }

    if ((sides[1] > sides[0]) && (sides[1] > sides[2]))
    {
        if ((sides[0] + sides[2] <= sides[1]) || ((sides[0] <= 0) || (sides[1] <= 0) || (sides[2] <= 0)))
        {
            printf("Nonexistent\n");
        }
        if (sides[0] + sides[2] > sides[1])
        {
            printf("Area: %.2lf\n", s);
        }
    }

    if ((sides[2] > sides[0]) && (sides[2] > sides[1]))
    {
        if ((sides[0] + sides[1] <= sides[2]) || ((sides[0] <= 0) || (sides[1] <= 0) || (sides[2] <= 0)))
        {
            printf("Nonexistent\n");
        }
        if (sides[0] + sides[1] > sides[2])
        {
            printf("Area: %.2lf\n", s);
        }
    }

    if ((sides[0] == sides[2]) && (sides[0] == sides[1]))
    {
        printf("Area: %.2lf\n", s);
    }


    

    return 0;
}


int main() {

    per();

    area();




    return 0;
}