#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int size;
    scanf("%d", &size);

    arr = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        *(arr + i) = i + 1;
    }
    int *ptr = arr;
    printf("Array elements in order: ");
    while (*ptr != '\0') {
        printf("%d ", *ptr++);
    }
    printf("\n");
    printf("Array elements in reverse: ");
    while (ptr > arr) {
        printf("%d ", *--ptr);
    }
    printf("\n");
    free(arr);
    return 0;
}
