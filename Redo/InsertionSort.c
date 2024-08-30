#include <stdio.h>

void insertion_sort(double ListNumber[], int size) {
    for (int i = 0; i < size; i++) {
        double key = ListNumber[i];
        int j = i - 1;

        while(j >= 0 && ListNumber[j] > key) {
            ListNumber[j + 1] = ListNumber[j];
            j -= 1;
        }
        ListNumber[j + 1] = key;
    }
}

void insertion_sort_descending(double ListNumber[], int size) {
    for (int i = 0; i < size; i++) {
        double key = ListNumber[i];
        int j = i - 1;

        while(j >= 0 && ListNumber[j] < key) {
            ListNumber[j + 1] = ListNumber[j];
            j -= 1;
        }
        ListNumber[j + 1] = key;
    }
}

int main() {
    int number;
    scanf("%d", &number);
    double ListNumber[number], value;
    for (int i = 0; i < number; i++) {
        scanf("%lf", &value);
        ListNumber[i] = value;
    }
    printf("Don't sort: \n");
    for (int i = 0; i < number; i++) {
        printf("%.2f ", ListNumber[i]);
    }
    printf("\n");
    printf("----------\n");
    insertion_sort(ListNumber, number);
    printf("Sort by ascending.\n");
    for (int i = 0; i < number; i++) {
        printf("%.3f ", ListNumber[i]);
    }
    printf("\n");
    printf("----------\n");
    printf("Sort by descending.\n");
    insertion_sort_descending(ListNumber, number);
    for (int i = 0; i < number; i++) {
        printf("%.5f ", ListNumber[i]);
    }
    printf("\n");
    printf("**********\n");
    return 0;

}
