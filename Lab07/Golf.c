#include <stdio.h>
#include <math.h>

int main() {
    double PI = 3.141592653589793;
    int zeta, velocaity;
    scanf("%d\n%d", &zeta, &velocaity);
    printf("theta (degree) : %d\n", zeta);
    printf("u (m/s) : %d\n", velocaity);
    double height = ((velocaity*velocaity) * sin((zeta * PI) / 180) * sin((zeta * PI) / 180) / (2*9.81));
    printf("h (m) : %.4f\n", height);
    return 0;

}
