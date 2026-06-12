# include "functions.h"
# include <stdarg.h>
# include <float.h>

double sum(int cnt, ...) {
    va_list args;
    double result = 0.0;
    va_start(args, cnt);
    for (int i = 0; i < cnt; i++) {
        result += va_arg(args, double);
    }
    va_end(args);
    return result;
}

double max(int cnt, ...) {
    va_list args;
    double result = -DBL_MAX;
    va_start(args, cnt);
    for (int i = 0; i < cnt; i++) {
        double current = va_arg(args, double);
        if (current > result) {
            result = current;
        }
    }
    va_end(args);
    return result;
}

double min(int cnt, ...) {
    va_list args;
    double result = DBL_MAX;
    va_start(args, cnt);
    for (int i = 0; i < cnt; i++) {
        double current = va_arg(args, double);
        if (current < result) {
            result = current;
        }
    }
    va_end(args);
    return result;
}

double avg(int cnt, ...) {
    va_list args;
    double total = 0.0;
    va_start(args, cnt);
    for (int i = 0; i < cnt; i++) {
        total += va_arg(args, double);
    }
    va_end(args);
    if (cnt > 0) {
        return (total / cnt);
    } else {
        return 0.0;
    }
}