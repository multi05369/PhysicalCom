#include <stdio.h>

int main() {
    int numA, numB;
    scanf("%d %d", &numA, &numB);
    if (numA == numB) {
        printf("%d + %d = %d\n", numA, numB, numA + numB);
    } else {
        printf("%d - %d = %d\n", numA, numB, numA - numB);
    }
}