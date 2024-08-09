#include <stdio.h>
#include <ctype.h>

int main() {
    int number;
    int count[26] = {0}, order[26] = {0}, order_index = 0;
    scanf("%d", &number);
    getchar();

    if (number == 0) {
        printf("\n");
        return 0;
    }

    for (int i = 0; i < number; i++) {
        char word;
        scanf(" %c", &word);
        word = tolower(word);
        int index = word - 'a';

        if (count[index] == 0) {
            order[order_index++] = index;
        }
        count[index]++;
    }

    for (int i = 0; i < order_index; i++) {
        printf("%c: %d\n", 'a' + order[i], count[order[i]]);
    }

    return 0;
}
