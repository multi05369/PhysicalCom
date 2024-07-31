#include <stdio.h>

int main() {
    int number, numX = 1;
    scanf("%d", &number);
    while (numX <= number) {
        printf("%d ", numX);
        numX++;
    }
    printf("\n");
    return 0;

}
