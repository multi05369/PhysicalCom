#include <stdio.h>

int main() {
    int numx, numY, numZ;
    scanf("%d\n%d\n%d", &numx, &numY, &numZ);
    if ((numx + numY > numZ) && (numY + numZ > numx) && (numx + numZ > numY)) {
        printf("Triangle is valid.\n");
    } else {
        printf("Triangle is not valid.\n");
    }
}