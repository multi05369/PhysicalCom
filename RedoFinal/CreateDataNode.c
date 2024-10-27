#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DataNode {
    char* data;
    struct DataNode* next;
} DataNode;

DataNode* createDataNode(char* data) {
    DataNode* newNode = (DataNode*) malloc(sizeof(DataNode));

    newNode->data = (char*)malloc(strlen(data) + 1);
    strcpy(newNode->data, data);

    newNode->next = NULL;
    return newNode;
}

int main() {
    char data[101];
    scanf("%[^\n]s", data);

    DataNode* pNew = createDataNode(data);

    printf("%s\n", pNew->data);
    printf("%p\n", (void*)pNew->next);

    free(pNew->data);
    free(pNew);
    return 0;
}
