#include <stdio.h>
#include <ctype.h>
#include <string.h>

int checkText(char nameOne[], char nameTwo[]);
void convert(char name[], char reName[]) {
    int i =0;
    for (i; i < strlen(name); i++) {
        if (isupper(name[i])) {
            reName[i] = tolower(name[i]);
        } else if  (islower(name[i])) {
            reName[i] = toupper(name[i]);
        } else {
            reName[i] = name[i];
        }
    }
    reName[i] = '\0';
}

int main() {
    char nameOne[101], nameTwo[101], convertNameOne[101], convertNameTWo[101];
    scanf("%[^\n]\n%[^\n]", nameOne, nameTwo);
    convert(nameOne, convertNameOne);
    convert(nameTwo, convertNameTWo);
    printf("*** Results ***\n");
    printf("%s\n", convertNameOne);
    printf("%s\n", convertNameTWo);
    printf("***************\n");
    if (checkText(nameOne, nameTwo)) {
        printf("Both strings are not the same.\n");
    } else {
        printf("Both strings are the same.\n");
    }
    return 0;

}

int checkText(char nameOne[], char nameTwo[]) {
    if (strlen(nameOne) != strlen(nameTwo)) {
        return 1;
    }

    for (int i = 0; i < strlen(nameOne); i++) {
        if (tolower(nameOne[i]) != tolower(nameTwo[i])) {
            return 1;
        }
    }

    return 0;
}
