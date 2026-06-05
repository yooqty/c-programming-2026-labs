#include <stdio.h>
#include <stdlib.h>

/*Разместить в динамической памяти 2 массива – 2 матрицы размерностью n на n с элементами типа double (значения n и элементы массивов ввести с консоли).
А также ввести с консоли знак операции: '+', '-' или '*'. Написать функцию, вычисляющую сумму, разность или произведение данных матриц (их передать по указателю)
и возвращающую указатель на массив-результат. Разместить эту функцию в отдельном модуле (отличном от того, где располагается функция main()).
Выдать на консоль значения полученного вектора.*/

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
	

	
	for (i=0; i<size; i++) {
		free(r[i]);
		free(Matrix1[i]);
		free(Matrix2[i]);
	}
	printf("ok");	
    free(Matrix1);
    free(Matrix2);
    free(r);


    return 0;
}
