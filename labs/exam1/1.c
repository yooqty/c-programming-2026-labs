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

    int day, month, year;
    fscanf(input, "%d %d %d", &day, &month, &year);
    fclose(input);

    int days_left = days_until_date(day, month, year);
    if (days_left < 0) {
        printf("Ошибка: дата должна быть в будущем (относительно 13.06.2026)\n");
        return 1;
    }

    printf("До даты %02d.%02d.%04d осталось дней: %d\n", day, month, year, days_left);

    int m = 4;
    printf("Размер матрицы m = %d\n", m);

    int*** matrices = NULL;
    int* sums = NULL;
    int count = 0;
    int found = 0;


    FILE* output = fopen("output.txt", "w");
    if (!output) {
        printf("Ошибка: не удалось создать output.txt\n");
        return 1;
    }

    fprintf(output, "--- Результат работы программы ---\n");
    fprintf(output, "До даты %02d.%02d.%04d осталось дней: %d\n\n", day, month, year, days_left);

    while (!found) {
        int** new_mat = create_matrix(m);
        int new_sum = sum_matrix(new_mat, m);
        for (int i = 0; i < count; i++) {
            if (sums[i] == new_sum) {
                fprintf(output, "Найдены две матрицы с одинаковой суммой элементов = %d\n\n", new_sum);
                print_matrix_to_file(output, matrices[i], m, "Матрица 1");
                print_matrix_to_file(output, new_mat, m, "Матрица 2");
                found = 1;
                break;
            }
        }
        if (found) {
            free_matrix(new_mat, m);
            break;
        }

    return 0;
}