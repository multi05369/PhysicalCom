#include <stdio.h>

int main() {
    int M[8] = {2, 20, 8, 10, 4, 6, 16, 18};
    int N[7] = {1, 3, 9, 7, 11, 15, 19};
    int number, i;
    for (i = 0; i <=99; i++) {
        scanf("%d", &number);
        if (number < 1 || number > 20) {
            continue;
        } 
        
        int found = 0;
        for (int j = 0; j < 8; j++) {
            if (M[j] == number) {
                printf("%d is in M at index [%d]\n", number, j);
                found = 1;
                break;
            } else if (N[j] == number) {
                printf("%d is in N at index [%d]\n", number, j);
                found = 1;
                break;
            }
        }
        
        if (!found) {
            printf("%d is not in neither M nor N\n", number);
        }
        break;
        }
        return 0;
    }
