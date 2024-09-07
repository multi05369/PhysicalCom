#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str;
    int lenght, freq;
    scanf("%d\n%d", &lenght, &freq);
    str = (char*) malloc(sizeof(char) * (lenght + 1));
    scanf(" %[^\n]s", str);
    char *ptr = str;
    while (*ptr != '\0' && ptr < str + lenght) {
        printf("%c", *ptr);
        ptr += freq;
    }
    printf("\n");
    free(str);
    return 0;

}
