#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX(array, n) ({ \
    int max = (array)[0];\
    for (int i = 1; i < (n); i++){\
       if ((array)[i]> max)\
          max = (array)[i];\
    }\
    max;\
})

int main() {
    char input[10000];
    int numbers[1000];
    int count = 0;
    



    return 0;
}