#include <stdio.h>

int main() {
    int number, summary;
    while (number != -9)
    {
        scanf("%d", &number);
        if (number != -9) {
            summary += number;
        }
    }
    printf("%d\n", summary);
    return 0;
    
}
