#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int papOne, papTwo;
    scanf("A%d\n", &papOne);
    scanf("A%d", &papTwo);
    printf("%.0f\n", pow(2, abs(papOne - papTwo)));
    return 0;
}
