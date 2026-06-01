#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int sum(int n, ...) {
    int res = 0;
    va_list list;
    va_start(list, n);
    while(n)
    {
        res += va_arg(list, int);
        --n;
    }
    va_end(list);
    return res;
}

int max(int n, ...) {
    int res = INT_MIN;
    va_list list;
    va_start(list, n);
    while(n)
    {
        int max = va_arg(list, int);
        if (max > res)
        {
            res = max;
        }
        --n;
    }
    va_end(list);
    return res;
}

int min(int n, ...) {
    int res = INT_MAX;
    va_list list;
    va_start(list, n);
    while(n)
    {
        int max = va_arg(list, int);
        if (max < res)
        {
            res = max;
        }
        --n;
    }
    va_end(list);
    return res;
}