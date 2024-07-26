#include <stdio.h>

int main() {
    float weight, height;
    scanf("%f\n%f", &height, &weight);
    height /= 100;
    float res = weight / (height*height);
    printf("%f\n", res);
}