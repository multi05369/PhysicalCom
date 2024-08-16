#include <stdio.h>

int fibonacci(int number) {
    if (number <= 0) {
        return 0;
    } else if (number == 1) {
        return 1;
    } else {
        return fibonacci(number - 1) + fibonacci(number - 2);
    }
}

int main() {
    int number;
    scanf("%d", &number);
    printf("method = %d\n", fibonacci(number) + fibonacci(number - 1));
    return 0;

}
