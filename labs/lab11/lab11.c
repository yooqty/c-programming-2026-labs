#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{   
    printf("numbers: 16, 8, 10, 4, 67.\n");
    printf("sum: %.2f\n", sum(5, 16.0, 8.0, 10.0, 4.0, 67.0));
    printf("max: %.2f\n", max(5, 16.0, 8.0, 10.0, 4.0, 67.0));
    printf("min: %.2f\n", min(5, 16.0, 8.0, 10.0, 4.0, 67.0));
    printf("avg: %.2f\n", avg(5, 16.0, 8.0, 10.0, 4.0, 67.0));
    
    return 0;
}