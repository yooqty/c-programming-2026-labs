#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int days_until_date(int day, int month, int year) {

    int cur_day = 13, cur_month = 6, cur_year = 2026;

    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int is_leap(int y) {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    int day_of_year(int d, int m, int y) {
        int days = 0;
        for (int i = 0; i < m - 1; i++) {
            days += days_in_month[i];
            if (i == 1 && is_leap(y)) days++;
        }
        days += d;
        return days;
    }

    if (year < cur_year || (year == cur_year && day_of_year(day, month, year) < day_of_year(cur_day, cur_month, cur_year))) {
        return -1;
    }

    int total_days = 0;

    for (int y = cur_year; y < year; y++) {
        total_days += 365 + is_leap(y);
    }

    total_days -= day_of_year(cur_day, cur_month, cur_year);

    total_days += day_of_year(day, month, year);

    return total_days;

}