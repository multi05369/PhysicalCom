#include <stdio.h>
 
int main()
{
    char num[6];
    scanf("%s", num);
    printf("%.1s", num);
    printf("%79s", "");
    printf("%3.2s", num);
    printf("%77s", "");
    printf("%5.3s", num);
    printf("%75s", "");
    printf("%7.4s", num);
    printf("%73s", "");
    printf("%9.5s", num);
    printf("%71s", "");
    return 0;
}
