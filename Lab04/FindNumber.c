#include <stdio.h>

int main() {
    float numA, numB, numC, mid;
    scanf("%f %f %f", &numA, &numB, &numC);
    if ((numA >= numB && numA <= numC) || (numA >= numC && numA <= numB)) {
        mid = numA;
    } else if ((numB >= numA && numB <= numC) || (numB >= numC && numB <= numA)) {
        mid = numB;
    } else if ((numC >= numA && numC <= numB) || (numC >= numB && numC <= numA)) {
        mid = numC;
    }
    printf("%.2f\n", mid);
    
    return 0;
}