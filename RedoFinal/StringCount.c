#include <stdio.h>
#include <ctype.h>

int main() {
    char find;
    char text[151];
    int count = 0;

    scanf("%c", &find);
    find = tolower(find);
    scanf(" %[^\n]s", text);
    for (int i = 0; i < 151; i++) {
        text[i] = tolower(text[i]);
    }
    for (int i = 0; i < 151; i++) {
        if ( find == text[i]) {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;

}