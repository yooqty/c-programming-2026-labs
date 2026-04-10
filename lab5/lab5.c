#include <stdio.h>
#include <stdlib.h>

int main() {

    int size;
    int operation;

    printf("Enter the size of the matrix NxN: ");
    scanf("%d", &size);




    double **Matrix1 = (double**)malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        Matrix1[i] = (double*)malloc(size * sizeof(double));
    }

    double **Matrix2 = (double**)malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        Matrix2[i] = (double*)malloc(size * sizeof(double));
    }




    printf("Enter the values of the elements of the first matrix: \n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%lf", &Matrix1[i][j]);
        }
    }

    printf("Enter the values of the elements of the second matrix: \n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%lf", &Matrix1[i][j]);
        }
    }





    printf("Enter the operation(+,-,*): ");
    scanf(" %c", &operation);




    if (operation == '+') {
        double **ResultMatrix = sum(Matrix1,Matrix2,size);
        printf("Result: \n");
        for (int i = 0; i < size; i++) {
            for (int j = 0; i < size; i++) {
                printf("%0.2lf", ResultMatrix[i][j]);
            }
        }
    }

    if (operation == '-') {
        double **ResultMatrix = substract(Matrix1,Matrix2,size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; i < size; i++) {
                printf("%0.2lf", ResultMatrix[i][j]);
            }
        }
    }

    if (operation == '*') {
        double **ResultMatrix = multiply(Matrix1,Matrix2,size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; i < size; i++) {
                printf("%0.2lf", ResultMatrix[i][j]);
            }
        }
    }

    return 0;
}