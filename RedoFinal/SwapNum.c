#include <stdio.h>

void swap(double *a, double *b, double *c) {
    double temp, tempTwo, tempThree;
    temp = *a;
    tempTwo = *b;
    tempThree = *c;
    *a = tempThree;
    *b = temp;
    *c = tempTwo;

}

int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    swap(&a, &b, &c);
    printf("a = %.2lf, b = %.2lf, c = %.2lf\n", a, b, c);
    return 0;
}
