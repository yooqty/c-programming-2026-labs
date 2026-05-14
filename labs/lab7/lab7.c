#include <stdio.h>

#define count 50

typedef struct {
    char n[50], fn[50], ln[50];
    int year;
} humen;

int main() {
    humen a[count], b[count];
    int i, j;
    humen temp;

    FILE *file = fopen("humen.txt", "r");
    for (i=0; i<count; i++) {
        fscanf(file, "%s", a[i].n);
        fscanf(file, "%s", a[i].fn);
        fscanf(file, "%s", a[i].ln);
        fscanf(file, "%d", a[i].n);
    }
    fclose(file);

    return 0;
}