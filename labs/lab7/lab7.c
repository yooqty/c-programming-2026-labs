#include <stdio.h>

/*Объявить тип-структуру humen, включающую имя человека, фамилию и год рождения. Объявить два массива из четырёх элементов типа humen.
Ввести с консоли или из файла элементы одного массива и построить на их основе другой, упорядочив элементы по годам рождения. Вывести результат.*/

typedef struct {
    char n[50], fn[50], ln[50];
    int year;
} humen;

int main() {
	
	int cnt = 0;
	char buff[256];
	FILE *file = fopen("humen.txt", "r");
	while (fgets(buff, sizeof(buff), file) != NULL)
	{
        if (strlen(buff) > 1) 
		{
            cnt++;
        }
    }
	fclose(file);
	
	
    humen a[cnt], b[cnt];
    int i, j;
    humen t;

    FILE *file2 = fopen("humen.txt", "r");
    for (i=0; i<cnt; i++) {
        fscanf(file, "%s", a[i].ln);
        fscanf(file, "%s", a[i].n);
        fscanf(file, "%s", a[i].fn);
        fscanf(file, "%d", &a[i].year);
    }
    fclose(file2);

    for (i=0; i<cnt; i++) {
        b[i] = a[i];
    }

    for (i=0; i<cnt-1; i++) {
        for (j=0; j<cnt-1; j++) {
            if (b[j].year > b[j+1].year) {
                t = b[j];
                b[j] = b[j+1];
                b[j+1] = t;
            }
        }
    }

    for (i=0; i<cnt; i++) {
    	if (strncmp(b[i].ln, "������", 6) == 0) {
    		printf("%s %s %s, %d\n", b[i].ln, b[i].n, b[i].fn, b[i].year);
		}
    }

    return 0;
}
