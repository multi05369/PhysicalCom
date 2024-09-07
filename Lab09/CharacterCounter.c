#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str;
    int lenght = 101, lower = 0, upper = 0, digit = 0;
    str = (char*) malloc(sizeof(char) * lenght);
    scanf("%[^\n]s", str);
    char *ptr = str;
    while (*ptr != '\0') {
        if (*ptr >= 65 && *ptr <= 90) {
            upper++;
        }
        if (*ptr >= 97 && *ptr <= 122) {
            lower++;
        }
        if (*ptr >= 48 && *ptr <= 57) {
            digit++;
        }
        ptr++;
    }
    printf("Lowercase letters: %d\n", lower);
    printf("Uppercase letters: %d\n", upper);
    printf("Digits: %d\n", digit);
    free(str);
    return 0;
    
}
