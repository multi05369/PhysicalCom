#include <stdio.h>
#include <stdlib.h>

int main()
{
    int std_number;
    char fullName[50];
    scanf("%d", &std_number);
    scanf(" %[^\n]s", fullName);
    printf("Hello! My name is %s, %d", fullName, std_number);
    return 0;
}
