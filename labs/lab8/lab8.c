#include <stdio.h>

typedef struct {
    char n[50];
    int year;
    char g[10];
    float h;
} person;

int sf[10];
int cnt=0;

int compare_people(const void * a, const void * b) {
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

    int count=0;
    char ln[50], fn[50];
    while (fscanf(f, " %s %s %d %s %f", ln, fn, & people[count].year, people[count].g, & people[count].h) == 5) {
        sprinf(people[count].n, "%s %s", ln, fn);
        count++;
    }
    fclose(f);
    
    printf("Sort by: n(name/last name), y(birth year), g(gender), h(height)\n");
    cnt=0;
    int input;
    while (scanf("%d", & input)==1 && input!=0 && cnt<10) {
        sf[cnt++] = input;
    }
    qsort(people, count, sizeof(person), compare_people);



    return 0;
}