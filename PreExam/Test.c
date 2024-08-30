#include <stdio.h>
#include <string.h>
// Gen from AI
void reverse(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void addLargeNumbers(char* num1, char* num2, char* result) {
    reverse(num1);
    reverse(num2);

    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = (len1 > len2) ? len1 : len2;

    int carry = 0;
    int i;
    for (i = 0; i < maxLen; i++) {
        int digit1 = (i < len1) ? num1[i] - '0' : 0;
        int digit2 = (i < len2) ? num2[i] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        result[i] = (sum % 10) + '0';
        carry = sum / 10;
    }

    if (carry) {
        result[i++] = carry + '0';
    }

    result[i] = '\0';

    reverse(result);

    reverse(num1);
    reverse(num2);
}

int main() {
    char num1[1000], num2[1000], result[1001];

    strcpy(num1, "1");
    strcpy(num2, "90");

    addLargeNumbers(num1, num2, result);

    printf("Sum: %s + %s = %s\n", num1, num2, result);

    return 0;
}
