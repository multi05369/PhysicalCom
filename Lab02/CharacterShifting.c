#include <stdio.h>
 
int main()
{
    char chr1, chr2, chr3, chr4, chr5;
    int num1, num3, num5;
    scanf("%c\n%c\n%c\n%c\n%c", &chr1, &chr2, &chr3, &chr4, &chr5);
    num1 = chr1;
    num3 = chr3;
    num5 = chr5;
    num1++;
    num3++;
    num5++;
    chr1 = num1;
    chr3 = num3;
    chr5 = num5;
    printf("%c\n%c\n%c\n%c\n%c", chr1, chr2, chr3, chr4, chr5);
    return 0;
}
