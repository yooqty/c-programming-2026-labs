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

}