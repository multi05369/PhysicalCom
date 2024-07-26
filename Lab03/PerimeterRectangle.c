#include <stdio.h>

int main() {
    double width, height;
    scanf("%lf\n%lf", &width, &height);
    printf("Perimeter of rectangle = %.4f units", (width + height) * 2);
    return 0;
}