#include <stdio.h>

int main() {
    int number, numX = 1;
    scanf("%d", &number);
    for (numX; numX <= number; numX++) {
        printf("%d ", numX);
    }
    printf("\n");
    return 0;

}
