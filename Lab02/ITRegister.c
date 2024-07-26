#include <stdio.h>
 
int main()
{
    char name[31], surname[31], std_ID[9];
    int date, month, year;
    double gpa;
    scanf("%s\n%s\n%s\n%d/%d/%d\n%lf", name, surname, std_ID, &date, &month, &year, &gpa);
    printf("Fullname: %s %s\n", name, surname);
    printf("ID: %s\n", std_ID);
    printf("DOB: %02d-%02d-%04d\n", date, month, year);
    printf("GPA: %.2f\n", gpa);
    return 0;
}
