#include <stdio.h>
#include <string.h>

struct student_info {
    char name[61];
    char surname[61];
    char sex[7];
    int age;
    char stdID[13];
    double avg;
};

int main() {
    struct student_info std;
    scanf("%s %s %s %d %s %lf", std.name, std.surname, std.sex, &std.age, std.stdID, &std.avg);
    printf("%s %c %s (%d) ID: %s GPA %.2lf\n", strcmp(std.sex, "Male") == 0 ? "Mr" : "Miss", std.name[0], std.surname, std.age, std.stdID, std.avg);
    return 0;
}
