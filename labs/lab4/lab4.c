#include <stdio.h>
#include "all.h"

/*Написать функции, вычисляющие периметр и площадь треугольника по значениям длин трёх его сторон.
Разместить их в отдельном модуле (отличном от того, где располагается функция main( )).
Ввести с консоли значения длин сторон треугольника (с проверкой на корректность неравенства треугольника) и выдать на консоль вычисленные с помощью написанных функций
значения его периметра и площади.*/

int main() {
    double a,b,c;
    printf("Enter the values of the sides of the triangle: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    if (! triangle (a,b,c)) {
        printf ("The triangle doesn't exist\n ");
        return 1;
    }

    double p = perimetr(a,b,c);
    double s = area(a,b,c);

    printf("Perimetr: %.2f\n ", p);
    printf ("Area: %.2f\n ", s);

return 0;
}