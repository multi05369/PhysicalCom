#include <stdio.h>

int main() {
    double kilo;
    scanf("%lf", &kilo);
    if ((kilo >= 0) && (kilo <= 5.032)) {
        printf("Bangkok\n");
    }
    else if ((kilo > 5.032) && (kilo <= 35.477)) {
        printf("Samut Prakarn\n");
    }
    else if ((kilo > 35.477) && (kilo <= 52.900)) {
        printf("Chachoengsao\n");
    }
    else if ((kilo > 52.900) && (kilo <= 58.855)) {
        printf("Chon Buri\n");
    }
    else {
        printf("InValid\n");
    }
    return 0;
}
