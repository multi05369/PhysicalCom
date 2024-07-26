#include <stdio.h>

int main() {
    char grade;
    scanf("%c", &grade);
    if ((grade == 'A') || (grade == 'a')) {
        printf("Genius\n");
    } else if ((grade == 'B') || (grade == 'b')) {
        printf("Good\n");
    } else if ((grade == 'C') || (grade == 'c')) {
        printf("Try Harder\n");
    } else if ((grade == 'D') || (grade == 'd')) {
        printf("Very Bad\n");
    } else if ((grade == 'F') || (grade == 'f')) {
        printf("Fail\n");
    } else {
        printf("Invalid Input\n");
    }
    return 0;
}
