#include <stdio.h>

int main() {
    char letter;
    scanf("%c", &letter);
    if (letter >= 48 && letter <= 57) {
        printf("number\n");
    } else if (letter >= 65 && letter <= 90) {
        printf("uppercase\n");
    } else if (letter >= 97 && letter <= 122) {
        printf("lowercase\n");
    } else {
        printf("error\n");
    }
    return 0;
}