#include <stdio.h>

#define cnt 20

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
        fscanf(file, "%d", a[i].year);
    }
    fclose(file);

    for (i=0; i<cnt; i++) {
        b[i] = a[i];
    }

    for (i=0; i<cnt; i++) {
        for (j=0; j<cnt; j++) {
            if (b[j].year > b[j+1].year) {
                temp = b[j];
                b[j] = b[j+1];
                b[j+1] = temp;
            }
        }
    }

    for (i=0; i<cnt; i++) {
        printf("%s %s %s, %d\n", b[i].n, b[i].fn, b[i].ln, b[i].year);
    }

    return 0;
}