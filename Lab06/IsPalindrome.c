#include <stdio.h>
#include <string.h>

int main() {
    char text[100], check[100];
    int j=0;
    scanf("%[^\n]", text);
    for (int i = strlen(text) - 1; i >= 0; i--) {
        check[j++] = text[i];
    }
    if (strcmp(text, check) == 0) {
        printf("It is Palindrome.\n");
    } else {
        printf("It is not Palindrome.\n");
    }
    return 0;

}
