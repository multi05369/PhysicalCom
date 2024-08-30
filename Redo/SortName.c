#include <stdio.h>
#include <string.h>
#include <ctype.h>

void insertion_sort(char name[][61], int size) {
    for (int i = 0; i < size; i++) {
        char key[61];
        strcpy(key, name[i]);
        int j = i - 1;

        while (j >= 0 && strcmp(key, name[j]) > 0) {
            strcpy(name[j + 1], name[j]);
            j -= 1;
        }
        strcpy(name[j + 1], key);
    }
}

void formatName(char name[]) {
    int len = strlen(name);
    name[0] = toupper(name[0]);
    for (int i = 1; i < len; i++) {
        if (name[i - 1] == ' ') {
            name[i] = toupper(name[i]);
        } else {
            name[i] = tolower(name[i]);
        }
    }

}

int main() {
    int number;
    scanf("%d", &number);
    char name[61], nameList[number][61];
    for (int i = 0; i < number; i++) {
        scanf(" %[^\n]", name);
        formatName(name);
        strcpy(nameList[i], name);
    }
    insertion_sort(nameList, number);

    for (int i = 0; i < number; i++) {
        printf("%s\n", nameList[i]);
    }
}