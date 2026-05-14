#include <stdio.h>

#define cnt 50

typedef struct {
    char n[50], fn[50], ln[50];
    int year;
} humen;

int main() {
    humen a[cnt], b[cnt];
    int i, j;
    humen temp;

    FILE *file = fopen("humen.txt", "r");
    for (i=0; i<cnt; i++) {
        fscanf(file, "%s", a[i].n);
        fscanf(file, "%s", a[i].fn);
        fscanf(file, "%s", a[i].ln);
        fscanf(file, "%d", a[i].n);
    }
    fclose(file);

    for (i=0; i<cnt; i++) {
        b[i] = a[i];
    }

    return 0;
}