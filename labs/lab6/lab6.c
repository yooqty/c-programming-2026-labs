#include <stdio.h>

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
