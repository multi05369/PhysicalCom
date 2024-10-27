#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str;
    int size = 0, cap = 10;
    char letter;

    str = (char*) malloc(sizeof(char) * cap);
    while (1) {
        scanf(" %c", &letter);
        if (letter == '-') {
            break;
        }

        if (size >= cap) {
            cap *= 2;
            char *temp = (char*) realloc(str, cap);
            str = temp;
        }

        *(str + size++) = letter;
    }

    char *ptr = str;
    while (*ptr != '\0') {
        printf("%c", *ptr++);
    }
    printf("\n");

    while (ptr > str) {
        printf("%c", *--ptr);
    }
    printf("\n");

    free(str);
    return 0;
}