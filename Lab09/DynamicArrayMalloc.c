#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, i;
    int *arr;
    scanf("%d", &size);
    arr = (int*)malloc(size * sizeof(int));
    for (i = 0; i < size; i++) {
        *(arr + i) = i + 1;
    }
    int *ptr = arr;

    printf("Array elements in order: ");
    while (ptr < arr + size)
    {
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
