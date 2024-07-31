#include <stdio.h>

int main() {
    int numA, numB;
    scanf("%d %d", &numA, &numB);
    if (numA < numB) {
        for (numA; numA <= numB; numA++) {
            printf("%d ", numA);
        }
        printf("\n");
    } else if (numA > numB) {
        for (numA; numA > numB - 1; numA--) {
            printf("%d ", numA);
        }
        printf("\n");
    }
    return 0;
}
