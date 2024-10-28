#include <stdio.h>
#include <string.h>

struct Book_info {
    char bookID[6];
    char bookName[21];
    double price;
    char author[31];
};

int main() {
    int num;
    scanf("%d", &num);
    char check[21];
    struct Book_info book[num];
    int found = 0;
    for (int i = 0; i < num; i++) {
        scanf("%s %s %lf %s", book[i].bookID, book[i].bookName, &book[i].price, book[i].author);
    }
    while (1) {
        scanf(" %[^\n]s", check);
        if (strcmp(check, "End") == 0) {
            break;
        }
        for (int i = 0; i < num; i++) {
            if (strcmp(check, book[i].bookName) == 0) {
                book[i].price -= ((book[i].price * 0.2));
                found = 1;
                printf("Book ID : %s, Name : %s, Price %.2lf Baht\n", book[i].bookID, book[i].bookName, book[i].price);
            }
        }
    }
    if (!found) {
        printf("none\n");
    }

    return 0;
}
