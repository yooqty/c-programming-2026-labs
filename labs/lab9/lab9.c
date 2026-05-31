#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[256];           
    double numbers[100];       
    char operations[100];      
    int num_count = 0;         
    int op_count = 0;          

    printf("Enter the expression: ");
    fgets(input, sizeof(input), stdin);

    int i = 0;
    while (input[i] != '\0') {
        if (input[i] == '\n') {
            input[i] = '\0';
            break;
        }
        i++;
    }
    
    char *ptr = input;
     
    while (*ptr == ' ') ptr++;

    numbers[num_count++] = strtod(ptr, &ptr);
    
    while (*ptr != '\0') {
        while (*ptr == ' ') ptr++;


        if (*ptr == '+' || *ptr == '-') {
            operations[op_count++] = *ptr;  
            ptr++;

            while (*ptr == ' ') ptr++;

            numbers[num_count++] = strtod(ptr, &ptr);
        } else {
            break;
        }
    }
    
    double result = numbers[0];

    for (i = 0; i < op_count; i++) {
        if (operations[i] == '+') {
            result = result + numbers[i + 1];
        } else {
            result = result - numbers[i + 1];
        }
    }

    printf("Result: %.2f\n", result);

    return 0;
}
