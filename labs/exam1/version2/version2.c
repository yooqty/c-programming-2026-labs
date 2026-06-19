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

    int** matrix1 = allocateMatrix(size, size);
    int** matrix2 = allocateMatrix(size, size);

    fillRandom(matrix1, size, size);
    fillRandom(matrix2, size, size);

    writeMatrix(inputFile, matrix1, size, size, "Matrix 1");
    writeMatrix(inputFile, matrix2, size, size, "Matrix 2");

    fclose(inputFile);

    freeMatrix(matrix1, size);
    freeMatrix(matrix2, size);

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input.txt\n");
        return 1;
    }

    char buffer[100];
    fscanf(inputFile, "%s", buffer);
    fscanf(inputFile, "%s", buffer);
    matrix1 = readMatrix(inputFile, size, size);

    fscanf(inputFile, "%s", buffer);
    fscanf(inputFile, "%s", buffer);
    matrix2 = readMatrix(inputFile, size, size);

    fclose(inputFile);

    int** multResult = multiplyMatrices(matrix1, matrix2, size);
    int** addResult = addMatrices(matrix1, matrix2, size);

    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error creating output.txt\n");
        return 1;
    }

    writeMatrix(outputFile, matrix1, size, size, "Matrix 1");
    writeMatrix(outputFile, matrix2, size, size, "Matrix 2");
    writeMatrix(outputFile, multResult, size, size, "Multiplication result (A * B)");
    writeMatrix(outputFile, addResult, size, size, "Addition result (A + B)");

    int minRow, minCol;
    findMinElement(matrix1, size, size, &minRow, &minCol);
    int oddCount = countOddNumbers(matrix1, size, size);

    fprintf(outputFile, "Minimum element in Matrix 1: [%d][%d] = %d\n", minRow, minCol, matrix1[minRow][minCol]);
    fprintf(outputFile, "Number of odd numbers in Matrix 1: %d\n\n", oddCount);

    int hasDup1 = hasDuplicateInRowOrCol(matrix1, size);
    int hasDup2 = hasDuplicateInRowOrCol(matrix2, size);

    if (hasDup1) {
        fprintf(outputFile, "Matrix 1 has identical numbers in a row or column:\n");
        writeMatrix(outputFile, matrix1, size, size, "Matrix 1");
    } else {
        fprintf(outputFile, "Matrix 1 does not have identical numbers in a row or column\n");
    }

    if (hasDup2) {
        fprintf(outputFile, "Matrix 2 has identical numbers in a row or column:\n");
        writeMatrix(outputFile, matrix2, size, size, "Matrix 2");
    } else {
        fprintf(outputFile, "Matrix 2 does not have identical numbers in a row or column\n");
    }

    fclose(outputFile);

    freeMatrix(matrix1, size);
    freeMatrix(matrix2, size);
    freeMatrix(multResult, size);
    freeMatrix(addResult, size);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Program execution time: %f seconds\n", cpu_time_used);

    return 0;
}