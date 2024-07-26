#include <stdio.h>

int main() {
    float num1, num2, num3, num4;
    scanf("%f\n%f\n%f\n%f", &num1, &num2, &num3, &num4);
    float sumNum = num1 + num2 + num3 + num4;
    float average = sumNum / 4;
    printf("Summation is %.2f\n", sumNum);
    printf("Average is %.3f\n", average);
    return 0;
}