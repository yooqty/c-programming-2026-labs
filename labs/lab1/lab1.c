#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    while(1){
    double a;
    printf("input a: ");
    scanf("%lf", &a);
    double b;
    printf("input b: ");
    scanf("%lf", &b);
    double c;
    printf("input c: ");
    scanf("%lf", &c);

    double D = pow(b,2) - 4*a*c;

    if (D>0){
        double x1 = ((-b) + sqrt(D)) / (2*a);
        double x2 = ((-b) - sqrt(D)) / (2*a);
        printf("%.2f, %.2f\n", x1,x2);
    }
    if (D==0){
        double x = (-b)/(2*a);
        printf("%.2f\n", x);
    }
    if (D<0){
        printf("no\n");
    }

    double z;
    printf("continue: 1(yes), 0(no)\n");
    scanf("%lf", &z);
    if (!z) break;
    }

    return 0;
}