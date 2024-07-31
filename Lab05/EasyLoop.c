#include <stdio.h>

int main() {
    int number;
    scanf("%d", &number);
    if (number < 0) {
        for (number; number<= 0; number++) {
            printf("%d ", number);
        }
    } else {
        for (number;number>=0; number--) {
            printf("%d ", number);
        }
    }
    printf("\n");
    return 0;
}
