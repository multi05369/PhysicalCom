#include <stdio.h>
#include <string.h>

struct Record {
    char id[10];
    char name[100];
    long salary;
    long sales;
};

int main() {
    int num;
    scanf("%d", &num);
    struct Record record[num];
    char find_id[10];
    for (int i = 0; i < num; i++) {
        scanf("%s %s %ld %ld", record[i].id, record[i].name, &record[i].salary, &record[i].sales);
        
    }
    scanf("%s", find_id);
    int index = 0, found = 0;
    for (index; index < num; index++) {
        if (strcmp(record[index].id, find_id) == 0) {
            printf("%s\n", record[index].id);
            printf("%s\n", record[index].name);
            printf("%ld\n", record[index].sales);
            printf("%.2lf\n", record[index].sales * 0.02);
            printf("%ld\n", record[index].salary);
            printf("%.2lf\n", record[index].salary + record[index].sales * 0.02);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("ID not found !!!\n");
    }
    return 0;

}
