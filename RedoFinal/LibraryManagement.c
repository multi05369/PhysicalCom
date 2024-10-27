#include <stdio.h>
#include <string.h>

int main() {
    int book_id;
    char id[5];
    scanf("%d", &book_id);
    if (book_id < 1000) {
        sprintf(id, "%d", book_id);
        char check;
        for (int i = 0; i < strlen(id); i++) {
            check = id[i];
        }
        if (check == '0' || check == '5') {
            printf("Science\n");
        } else if (check == '3' || check == '7') {
            printf("Literature\n");
        } else {
            printf("General Collection\n");
        }
    } else if (book_id >= 1000) {
        sprintf(id, "%d", book_id);
        char check;
        int lastTwo = ((id[2] - '0') * 10) + (id[3] - '0');
        if (lastTwo % 4 == 0) {
            printf("Reference\n");
        } else if (lastTwo == 11 || lastTwo == 22 || lastTwo == 33) {
            printf("History\n");
        } else {
            printf("Unclassified\n");
        }
    }

    return 0;

}
