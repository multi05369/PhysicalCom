#include <stdio.h>

int main() {
    double SBP, DBP;
    scanf("%lf\n%lf", &SBP, &DBP);
    if (SBP > 140 || DBP > 90) {
        printf("Hypertension\n");
    } else {
        printf("Normal\n");
    }
    return 0;
}
