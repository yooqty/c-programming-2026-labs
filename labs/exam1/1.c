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

int** create_matrix(int m) {

    int** mat = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        mat[i] = (int*)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            mat[i][j] = rand() % 10;
        }
    }
    return mat;

}

int sum_matrix(int** mat, int m) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            sum += mat[i][j];
        }
    }
    return sum;
}

void print_matrix_to_file(FILE* f, int** mat, int m, const char* name) {
    fprintf(f, "%s:\n", name);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(f, "%d ", mat[i][j]);
        }
        fprintf(f, "\n");
    }
    fprintf(f, "\n");
}

void free_matrix(int** mat, int m) {
    for (int i = 0; i < m; i++) free(mat[i]);
    free(mat);
}

int main() {
    clock_t start_time = clock();

    srand(time(NULL));

    FILE* input = fopen("input.txt", "r");
    if (!input) {
        printf("Ошибка: файл input.txt не найден!\n");
        return 1;
    }


    return 0;
}