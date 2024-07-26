#include <stdio.h>

int main() {
    char letter;
    scanf("%c", &letter);
    if (letter >= 97 && letter <= 122) {
        printf("%c\n", letter - 32);
    } else if (letter >= 65 && letter <= 90) {
        printf("%c\n", letter + 32);
    } else {
        printf("error\n");
    }
    return 0;
}
