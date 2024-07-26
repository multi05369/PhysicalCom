#include <stdio.h>

int main() {
    int second, minute, hour, day, realSec;
    scanf("%d", &second);
    day = second / 86400;
    hour = (second / 3600) % 24;
    minute = (second / 60) % 60;
    realSec = second % 60;
    printf("%d s = %d d %d h %d m %d s\n", second, day, hour, minute, realSec);
    return 0;
}