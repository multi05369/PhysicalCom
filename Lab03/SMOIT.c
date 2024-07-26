#include <stdio.h>

int main() {
    double price, percent, item, salePrice;
    scanf("%lf\n%lf\n%lf", &price, &percent, &item);
    salePrice = price - (price * percent/100);
    printf("%.2f\n", salePrice * item);
    return 0;
}