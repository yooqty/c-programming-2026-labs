#include <stdio.h>

typedef struct {
    char n[50];
    int year;
    char g[10];
    float h;
} person;

int sf[10];
int cnt=0;

int compare_fields(const void * a, const void * b) {
    person * p1 = ( person *) a;
    person * p2 = ( person *) b;
    int i;

    for (i=0; i<cnt; i++) {
        int field = sf[i];
        int cmp=0;

        switch(field) {
            case 1:
                cmp = strcmp(p1->n, p2->n);
                break;
            case 2:
                if (p1->year < p2->year) cmp=-1;
                else if (p1->year > p2->year) cmp=1;
                break;
            case 3:
                cmp = strcmp(p1->g, p2->g);
                break;
            case 4:
                if (p1->h < p2->h) cmp=-1;
                else if (p1->h > p2->h) cmp=1;
                break;
        }
        if (cmp!=0) return cmp;
    }
    return 0;
}

int main() {
    FILE *f = fopen("femboys.txt", "r");
    person people[100];

    int cunt=0;
    char ln[50], fn[50];
    while (fscanf(f, " %s %s %d %s %f", ln, fn, & people[cunt].year, people[cunt].g, & people[cunt].h) == 5) {
        sprinf(people[cnt].n, "%s %s", ln, fn);
        cunt++;
    }
    fclose(f);
    




    return 0;
}