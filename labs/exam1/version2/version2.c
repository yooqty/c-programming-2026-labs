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

int** readMatrix(FILE* file, int rows, int cols) {
    int** mat = allocateMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(file, "%d", &mat[i][j]);
        }
    }
    return mat;
}

int** multiplyMatrices(int** A, int** B, int size) {
    int** result = allocateMatrix(size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

int** addMatrices(int** A, int** B, int size) {
    int** result = allocateMatrix(size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

void findMinElement(int** mat, int rows, int cols, int* minRow, int* minCol) {
    *minRow = 0;
    *minCol = 0;
    int minVal = mat[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] < minVal) {
                minVal = mat[i][j];
                *minRow = i;
                *minCol = j;
            }
        }
    }
}

int countOddNumbers(int** mat, int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] % 2 != 0) {
                count++;
            }
        }
    }
    return count;
}

int hasDuplicateInRowOrCol(int** mat, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = j + 1; k < size; k++) {
                if (mat[i][j] == mat[i][k]) {
                    return 1;
                }
            }
        }
    }
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size; i++) {
            for (int k = i + 1; k < size; k++) {
                if (mat[i][j] == mat[k][j]) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    srand(time(NULL));

    int size;
    printf("Enter matrix size (N x N): ");
    scanf("%d", &size);

    FILE* inputFile = fopen("input.txt", "w");
    if (inputFile == NULL) {
        printf("Error creating input.txt\n");
        return 1;
    }



    return 0;
}