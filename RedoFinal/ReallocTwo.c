#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int *arr = NULL;
    int size = 0, capacity = 10, num;

    arr = (int*) malloc(sizeof(int) * capacity);

    while (1) {
        scanf(" %d", &num);
        if (num == -1) {
            break;
        }

        if (size >= capacity) {
            capacity *= 2;
            int *temp = (int*) realloc(arr, capacity);
            arr = temp;
        }

        *(arr + size++) = num;
    }
    printf("You entered: ");
    int *ptr = arr;
    while (*ptr != '\0') {
        printf("%d ", *ptr++);
    }
    printf("\n");

    qsort(arr, size, sizeof(int), compare);

    ptr = arr;
    printf("Sorted array: ");
    while (*ptr != '\0') {
        printf("%d ", *ptr++);
    }
    printf("\n");

    free(arr);
    return 0;
}