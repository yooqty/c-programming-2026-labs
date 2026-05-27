#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char n[50];
    int year;
    char g[10];
    float h;
} person;

int *sf;
int sf_capacity = 10;
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
    sf = (int*)malloc(sf_capacity * sizeof(int));
    if (sf == NULL) {
        printf("Memory allocation error!\n");
        return 1;
    }

    FILE *f = fopen("femboys.txt", "r");
    person people[100];

    int count=0;
    char ln[50], fn[50];
    while (fscanf(f, " %s %s %d %s %f", ln, fn, & people[count].year, people[count].g, & people[count].h) == 5) {
        sprintf(people[count].n, "%s %s", ln, fn);
        count++;
    }
    fclose(f);
    
    printf("Sort by: n(name/last name), y(birth year), g(gender), h(height)\n1 character per line\n(type q to quit)\n");
    cnt=0;
    int pr;
    pr=1;
    char input;
    
    while (cnt<10) {
    	printf("Sort priority %d: ", pr++);
    	scanf(" %c", &input);
    	
    	if (input == 'q' || input == 'Q') {
    		break;
		}
		
		int fld = 0;
		switch(input) {
			case 'n': case 'N': fld = 1; break;
			case 'y': case 'Y': fld = 2; break;
			case 'g': case 'G': fld = 3; break;
			case 'h': case 'H': fld = 4; break;
			default:
				printf("Invalid input!\n");
				continue;	
		}
		
		sf[cnt++] = fld;
	}
	
	printf("Femboys sorted by priority: ");
	int i;
    for (i = 0; i < cnt; i++) {
        char c;
        switch(sf[i]) {
            case 1: c = 'n'; break;
            case 2: c = 'y'; break;
            case 3: c = 'g'; break;
            case 4: c = 'h'; break;
        }
        printf("%c ", c);
    }
    printf("\n");
    
    qsort(people, count, sizeof(person), compare_people);

    FILE *f2 = fopen("sorted_femboys.txt", "w");
    for (i=0; i<count; i++) {
        fprintf(f2, "%-20s %4d %s %.2f\n", people[i].n, people[i].year, people[i].g, people[i].h );
    }
    fclose(f2);
    
    return 0;
}