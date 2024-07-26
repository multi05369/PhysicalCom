#include <stdio.h>
 
int main()
{
    char txtOne[30], txtTwo[30], txtThree[30], txtFour[30];
    scanf("%s", txtOne);
    scanf("%s", txtTwo);
    scanf("%s", txtThree);
    scanf("%s", txtFour);
    printf("String 1: %.3s\n", txtOne);
    printf("String 2: %.4s\n", txtTwo);
    printf("String 3: %.5s\n", txtThree);
    printf("String 4: %.6s", txtFour);
    return 0;
}
