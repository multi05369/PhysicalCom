#include <stdio.h>

int main() {
    double pi = 3.14159265359;
    double height, raduis, volume;
    int price;
    scanf("%d\n%lf\n%lf", &price, &raduis, &height);
    volume = height * pi * ((raduis / 2) * (raduis / 2));
    printf("Volume : %.2fml\n", volume);
    printf("Baht/ml : %.4f\n", price / volume);
    return 0;
}