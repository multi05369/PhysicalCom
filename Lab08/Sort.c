#include <stdio.h>

void insertion_sort(double numList[], int num) {
    for (int i = 0; i < num; i++) {
        double key;
        key = numList[i];
        int j = i - 1;

        while (j >= 0 && numList[j] > key) {
            numList[j + 1] = numList [j];
            j -= 1;
        }
        numList[j + 1] = key;
    }
}
int main() {
    int num;
    scanf("%d", &num);
    double numList[num], value;
    for (int i = 0; i < num; i++) {
        scanf("%lf", &value);
        numList[i] = value;
    }
    insertion_sort(numList, num);
    for (int i = 0; i < num; i++) {
        printf("%.2f ", numList[i]);
    }
    printf("\n");
    return 0;
}
