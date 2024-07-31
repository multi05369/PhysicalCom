#include <stdio.h>

int main() {
    int age, height, weight, avgAge, sumAge;
    float avgHeight, avgWeight, sumHeight, sumWeight;
    int countA =0, countB=0, countC=0, countD=0;
    for (int i = 1; i <= 50; i++) {
        scanf("%d %d %d", &age, &height, &weight);
        if ((age >= 20) && (height >= 160)) {
            countA++;
        }
        if ((age < 20) && ((height <= 180) || (weight >= 60))) {
            countB++;
        }
        if ((age >= 30) && (weight >= 40) && (weight <= 80)) {
            countC++;
        }
        if ((age < 40) && ((weight < 85) || (height <= 200))) {
            countD++;
        }
        sumAge += age;
        sumHeight += height;
        sumWeight += weight;
    }
    avgAge = sumAge / 50;
    avgHeight = sumHeight / 50;
    avgWeight = sumWeight / 50;
    printf("Age >= 20 and Height >= 160: %d\n", countA);
    printf("Age < 20 and Height <= 180 or Weight >= 60: %d\n", countB);
    printf("Age >= 30 and Weight >= 40 and Weight <= 80: %d\n", countC);
    printf("Age < 40 and Weight < 85 or Height <= 200: %d\n", countD);
    printf("Average Age: %d\n", avgAge);
    printf("Average Height: %.2f\n", avgHeight);
    printf("Average Weight: %.2f\n", avgWeight);
    return 0;
}
