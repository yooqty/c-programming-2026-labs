#include <stdio.h>

/*Создать текстовый файл с записями следующего вида:

Иванов Петр Сергеевич 1975
Сидоров Николай Андреевич 1981
….
Воробьянинов Ипполит Матвеевич 1978

Прочитать данные из этого файла и записать в другой только те строки, которые относятся к родившимся позднее 1980 года.*/

int main() {

    FILE *femboys = fopen("femboys.txt", "r");
    FILE *futanari = fopen("futanari.txt", "w");

    char ln[50], n[50], fn[50];
    int year;

    while (fscanf(femboys, "%s %s %s %d", ln, n, fn, &year) == 4) {
        if ( year > 1980 && strncmp(ln, "Петров", 6) == 0) {
            fprintf(futanari, "%s %s %s %d\n", ln, n, fn, year);
        }
    }

    fclose(femboys);
    fclose(futanari);

    return 0;
}
