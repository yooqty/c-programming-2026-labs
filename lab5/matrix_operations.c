#include <stdio.h>
#include <stdlib.h>
#include "matrix_operations.h"

double **sum(double **Matrix1, double **Matrix2, int size) {
    
    double **ResultMatrix;
    int i, j;
    
    ResultMatrix = (double**)malloc(size * sizeof(double*));
    for (i = 0; i < size; i++) {
        ResultMatrix[i] = (double*)malloc(size*sizeof(double));
    }

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            ResultMatrix[i][j] = Matrix1[i][j] + Matrix2[i][j];
        }
    }
    return ResultMatrix;
}




double **substract(double **Matrix1, double **Matrix2, int size) {

    double **ResultMatrix;
    int i, j;

    ResultMatrix = (double**)malloc(size * sizeof(double*));
    for (i = 0; i < size; i++) {
        ResultMatrix[i] = (double*)malloc(size*sizeof(double));
    }

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            ResultMatrix[i][j] = Matrix1[i][j] - Matrix2[i][j];
        }
    }
    return ResultMatrix;
}




double **multiply(double **Matrix1, double **Matrix2, int size) {

    double **ResultMatrix;
    int i, j, k;

    ResultMatrix = (double**)malloc(size * sizeof(double*));
    for (i = 0; i < size; i++) {
        ResultMatrix[i] = (double*)malloc(size*sizeof(double));
    }

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            ResultMatrix[i][j] = 0;
            for (k = 0; k < size; k++) {
                ResultMatrix[i][j] += Matrix1[i][k] + Matrix2[k][j];
            }
        }
    }
    return ResultMatrix;
}
