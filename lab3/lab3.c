#include <stdio.h>
#include <string.h>

int main() {

    char str[] = " ";
    int i;

    printf("Enter the string (up to 80 characters): ");
    scanf("%80s", &str);

    printf("%s \n", str);


    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == 'a')
        {
            str[i] = 'A';
        }
        if (str[i] == 'b')
        {
            str[i] = 'B';
        }
    }

    printf("%s \n", str);



    
    return 0;
}