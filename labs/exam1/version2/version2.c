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