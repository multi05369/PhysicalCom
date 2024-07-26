#include <stdio.h>

int main() {
    int price, percent, item;
    float promoPrice, promoPriceTwo;
    scanf("%d\n%d\n%d", &price, &percent, &item);
    float promoOne = price - ((price * percent) / 100);
    promoPrice = promoOne * item;
    float promoTwo = item - (item / 3);
    promoPriceTwo = promoTwo * price;
    if (promoPrice <= promoPriceTwo) {
        printf("Discount %d%%\n%.2f\n", percent, promoPrice);
    } else {
        printf("Buy 2 Get 1\n");
        printf("%.2f\n", promoPriceTwo);
    }
    return 0;
}