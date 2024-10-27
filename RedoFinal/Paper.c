#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int paperOne, paperTwo;
    scanf("A%d\n", &paperOne);
    scanf("A%d", &paperTwo);
    if (paperOne == paperTwo) {
        printf("1\n");
        return 0;
    }
    int remain = abs(paperOne - paperTwo);
    int res = 2;
    for (int i = 0; i < remain - 1; i++) {
        res *= 2;
    }
    printf("%d\n", res);

    return 0;
}
