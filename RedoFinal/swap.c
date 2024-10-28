#include <stdio.h>

void swapOne(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swapTwo(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10;
    int y = 20;
    printf("Start : x = %d, y = %d\n", x, y);
    swapOne(x, y);
    printf("Swap1 : x = %d, y = %d\n", x, y);
    swapTwo(&x, &y);
    printf("Swap2 : x = %d, y = %d\n", x, y);
    return 0;
}
