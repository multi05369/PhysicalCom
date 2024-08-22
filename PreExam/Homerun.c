#include <stdio.h>

int main() {
    int num, homerun = 0;
    double hitRange, area;
    scanf("%d", &num);
    scanf("%lf", &hitRange);
    for (int i = 1; i <= num; i++) {
        scanf("%lf", &area);
        if (hitRange > area) {
            homerun++;
        }
    }
    printf("%d\n", homerun);
    return 0;
}
