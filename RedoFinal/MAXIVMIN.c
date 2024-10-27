#include <stdio.h>
#include <string.h>

int findMax(int number[]) {
    int max = number[0];
    for (int i = 0; i < 6; i++) {
        if (number[i] > max) {
            max = number[i];
        }
    }
    return max;
}

int findMin(int number[]) {
    int min = number[0];
    for (int i = 0; i < 5; i++) {
        if (number[i] < min) {
            min = number[i];
        }
    }
    return min;
}

int main() {
    char sortby[4];
    scanf(" %[^\n]s", sortby);
    int number[6];
    for (int i = 0; i < 5; i++) {
        scanf("%d", &number[i]);
    }
    if (strcmp(sortby, "MAX") == 0) {
        printf("MAX : %d\n", findMax(number));
    } else if (strcmp(sortby, "MIN") == 0) {
        printf("MIN : %d\n", findMin(number));
    }

    return 0;

}