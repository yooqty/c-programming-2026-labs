#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX(array, n) ({int max = (array)[0]; for (int i = 1; i < (n); i++) {if ((array)[i] > max) max = (array)[i];} max;})

int main() {
    char input[10000];
    int numbers[1000];
    int cnt = 0;
    
    printf(" Enter the numbers: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf(" Input error!");
        return 1;
    }

    char *wlw = strtok(input, " \n");
    while (wlw != NULL && cnt < 1000) {
        int num = atoi(wlw);
        numbers[cnt] = num;
        cnt++;
        wlw = strtok(NULL, " \n");
    }

    int max = MAX(numbers,cnt);

    printf(" Max number: %d", max);

    return 0;
}