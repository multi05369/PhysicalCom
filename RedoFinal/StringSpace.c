#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str;
    int size = 151;
    str = (char*) malloc(sizeof(char) * size);
    scanf("%[^\n]s", str);
    char *ptr = str;
    while (*ptr != '\0') {
        if (*ptr == ' ') {
            ptr++;
            continue;
        }
        printf("%c", *ptr++);
    }
    printf("\n");
    free(str);
    return 0;
}
