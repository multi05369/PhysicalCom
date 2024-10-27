#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char text[151];
    char word;

    scanf(" %[^\n]s", text);
    int index = 0, line = 0;
    while (text[index] != '\0') {
        if (text[index] == ' ') {
            line++;
        }
        index++;
    }
    printf("%d words\n", line + 1);
    printf("----\n");
    int count;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] != ' ') {
            printf("%c", text[i]);
            count++;
        } else {
            printf(" : %d\n", count);
            count = 0;
        }
    }
    if ( count > 0) {
        printf(" : %d\n", count);
    }
    return 0;
}