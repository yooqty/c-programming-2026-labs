#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** allocateMatrix(int rows, int cols) {
    int** mat = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        mat[i] = (int*)malloc(cols * sizeof(int));
    }
    return mat;
}

void freeMatrix(int** mat, int rows) {
    for (int i = 0; i < rows; i++) {
        free(mat[i]);
    }
    free(mat);
}

void fillRandom(int** mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat[i][j] = rand() % 10;
        }
    }
}

void writeMatrix(FILE* file, int** mat, int rows, int cols, const char* name) {
    fprintf(file, "%s:\n", name);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%d ", mat[i][j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
}