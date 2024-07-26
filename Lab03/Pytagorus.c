#include <stdio.h>
#include <math.h>

int main(){
    double num1, num2, res;
    scanf("%lf\n%lf", &num1, &num2);
    res = pow(num1, 2) + pow(num2, 2);
    printf("%.2lf\n", sqrt(res));
    return 0;
}