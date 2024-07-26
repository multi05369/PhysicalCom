#include<stdio.h>

int main() {
    float price, percent;
    int amount;
    scanf("%f %f %d", &price, &percent, &amount);

    float discountPrice = price - ((price * percent) / 100);
    float discountResult = discountPrice * amount;

    int bonusAmount = amount - (amount / 3);
    float bonusResult = bonusAmount * price;

    if (discountResult <= bonusResult) {
        printf("Discount %d%%\n%.2lf", (int) percent, discountResult);
    } else {
        printf("Buy 2 Get 1\n%.2lf", bonusResult);
    }

    return 0;
}