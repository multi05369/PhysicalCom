#include <stdio.h>

int main() {
    char string1[31], string2[31], string3[31], string4[31];
    scanf("%s\n%s\n%s\n%s", string1, string2, string3, string4);
    printf("String 1: %.3s\nString 2: %.4s\nString 3: %.5s\nString 4: %.6s\n", string1, string2, string3, string4);
    return 0;

}
