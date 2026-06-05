#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <float.h>

double sum(int n, ...) {
    double res = 0;
    va_list list;
    va_start(list, n);
    while(n)
    {
        res += va_arg(list, double);
        --n;
    }
    va_end(list);
    return res;
}

double max(int n, ...) {
    double res = -DBL_MAX;
    va_list list;
    va_start(list, n);
    while(n)
    {
        double max = va_arg(list, double);
        if (max > res)
        {
            res = max;
        }
        --n;
    }
    va_end(list);
    return res;
}

double min(int n, ...) {
    double res = DBL_MAX;
    va_list list;
    va_start(list, n);
    while(n)
    {
        double max = va_arg(list, double);
        if (max < res)
        {
            res = max;
        }
        --n;
    }
    va_end(list);
    return res;
}

double avg(int n, ...) {
    double res = 0;
    double count = n;
    va_list list;
    va_start(list, n);
    while(n)
    {
        res += va_arg(list, double);
        --n;
    }
    va_end(list);
    return (double)res/count;
}