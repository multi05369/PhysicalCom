#include <stdio.h>

int main() {
    double score;
    scanf("%lf", &score);
    if ((score >= 80) && (score <= 100)) {
        printf("A\n");
    } else if ((score >= 70) && (score <= 79.99)) {
        printf("B\n");
    } else if ((score >= 60) && (score <= 69.99)) {
        printf("C\n");
    } else if ((score >= 50) && (score <= 59.99)) {
        printf("D\n");
    } else if ((score >= 0) && (score <= 49.99)) {
        printf("F\n");
    } else {
        printf("Out of Range\n");
    }
    return 0;
}