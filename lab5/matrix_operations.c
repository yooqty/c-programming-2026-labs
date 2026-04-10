#include <stdio.h>
#include <stdlib.h>
#include "matrix_operations.h"

int **sum(double **Matrix1, double **Matrix2, double size) {
    
    double **ResultMatrix;

    ResultMatrix = (double**)malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        ResultMatrix[i] = (double*)malloc(size*sizeof(double));
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            ResultMatrix[i][j] = Matrix1[i][j] + Matrix2[i][j];
        }
    }
    return ResultMatrix;
}




int **substract(double **Matrix1, double **Matrix2, double size) {

    double **ResultMatrix;

    ResultMatrix = (double**)malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        ResultMatrix[i] = (double*)malloc(size*sizeof(double));
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            ResultMatrix[i][j] = Matrix1[i][j] - Matrix2[i][j];
        }
    }
    return ResultMatrix;
}




int **multiply(double **Matrix1, double **Matrix2, double size) {

    double **ResultMatrix;

    ResultMatrix = (double**)malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        ResultMatrix[i] = (double*)malloc(size*sizeof(double));
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            ResultMatrix[i][j] = 0;
            for (int k = 0; k < size; k++) {
                ResultMatrix[i][j] += Matrix1[i][k] + Matrix2[k][j];
            }
        }
    }
    return ResultMatrix;
}