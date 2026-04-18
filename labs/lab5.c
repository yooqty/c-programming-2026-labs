#include <stdio.h>
#include <stdlib.h>

int main() {

    int size;
    int operation;
    int i, j;

    printf("Enter the size of the matrix NxN: ");
    scanf("%d", &size);




    double **Matrix1 = (double**)malloc(size * sizeof(double*));
    for (i = 0; i < size; i++) {
        Matrix1[i] = (double*)malloc(size * sizeof(double));
    }

    double **Matrix2 = (double**)malloc(size * sizeof(double*));
    for (i = 0; i < size; i++) {
        Matrix2[i] = (double*)malloc(size * sizeof(double));
    }

    double **r = (double**)malloc(size * sizeof(double*));
    for (i = 0; i < size; i++) {
        r[i] = (double*)malloc(size * sizeof(double));
    }



    printf("Enter the values of the elements of the first matrix: \n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            scanf("%lf", &Matrix1[i][j]);
        }
    }

    printf("Enter the values of the elements of the second matrix: \n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            scanf("%lf", &Matrix2[i][j]);
        }
    }





    printf("Enter the operation(+,-,*): ");
    scanf(" %c", &operation);
    
    
	if (operation=='+'){
		r = sum(Matrix1,Matrix2,size);
		printm(r,size);
	}
	
	if (operation=='-'){
		r = substract(Matrix1,Matrix2,size);
		printm(r,size);
	}
	
	if (operation=='*'){
		r = multiply(Matrix1,Matrix2,size);
		printm(r,size);
	}


    return 0;
}
