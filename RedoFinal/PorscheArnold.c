#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str;

    str = (char*) malloc(sizeof(char) * 15);

    strcpy(str, "Porsche Arnold");

    char *ptr = str;

    while (*ptr != '\0') {
        printf("%c", *ptr++);
    }
    printf("\n");
    free(str);
    return 0;
}