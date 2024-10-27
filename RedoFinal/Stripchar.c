#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);

    if (num < 1000) {
        if (num % 10 == 0) {
            printf("Command-class starship\n");
        } else if (num % 10 == 5) {
            printf("Exploration-class starship\n");
        } else {
            printf("General-class starship\n");
        }
    } else if (num >= 1000) {
        int temp = num;
        while (temp >= 10) {
            temp /= 10;
        }
        if (temp % 2 == 0) {
            printf("Active ");
        } else {
            printf("Reserve ");
        }
        if (num % 100 == 50 || num % 100 == 75) {
            printf("Starfleet Flagship");
        } else {
            printf("Standard-class starship");
        }
        printf("\n");
    }
    return 0;
}
