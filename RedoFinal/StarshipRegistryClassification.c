#include <stdio.h>

int main() {
    int number;
    char num[11];
    scanf("%d", &number);

    if (number < 1000) {
        if (number % 10 == 0) {
            printf("Command-class starship\n");
        } else if (number % 10 == 5) {
            printf("Exploration-class starship\n");
        } else {
            printf("General-class starship\n");
        }
    } else if (number >= 1000) {
        sprintf(num, "%d", number);
        int firstDigit = num[0] - '0';
        if (firstDigit % 2 == 0) {
            printf("Active ");
        } else {
            printf("Reserve ");
        }
        if (number % 100 == 50 || number % 100 == 75) {
            printf("Starfleet Flagship");
        } else {
            printf("Standard-class starship");
        }
        printf("\n");
    }
    return 0;
}
