#include <stdio.h>
#include <stdbool.h>

int main() {
    int num, age;
    double maxWeight, sumWeight = 0, weight;
    bool checkChild = true;
    scanf("%d\n%lf", &num, &maxWeight);
    if (num == 0) {
        checkChild = false;
    }
    for (int i = 0; i < num; i++) {
        scanf("%d\n%lf", &age, &weight);
        if (age >= 12) {
            checkChild = false;
        }
        sumWeight += weight;
    }
    if (!checkChild && maxWeight >= sumWeight) {
        printf("Safe\n");
    } else {
        printf("Not Safe\n");
    }
    return 0;
}
