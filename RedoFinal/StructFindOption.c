#include <stdio.h>
#include <string.h>

struct Student_Info {
    char name[61];
    char surname[61];
    char sex[7];
    int age;
    char stdID[13];
    double gpa;
};

int main() {
    struct Student_Info std[20];
    double grade;
    for (int i = 0; i < 20; i++) {
        scanf("%s %s %s %d %s %lf", std[i].name, std[i].surname, std[i].sex, &std[i].age, std[i].stdID, &std[i].gpa);
    }
    scanf("%lf", &grade);

    for (int i = 0; i < 20; i++) {
        if (grade == std[i].gpa) {
            printf("%s %c %s (%d) ID: %s GPA %.2lf\n", strcmp(std[i].sex, "Male") == 0 ? "Mr" : "Miss", std[i].name[0], std[i].surname, std[i].age, std[i].stdID, std[i].gpa);
        }
    }
    return 0;
}
