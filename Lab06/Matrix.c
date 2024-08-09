#include <stdio.h>
#define ROWS 3
#define COLS 3

int main() {
    double mat1[ROWS][COLS], mat2[ROWS][COLS], res[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        scanf("%lf %lf %lf", &mat1[i][0], &mat1[i][1], &mat1[i][2]);
    }
    for (int j = 0; j < ROWS; j++) {
        scanf("%lf %lf %lf", &mat2[j][0], &mat2[j][1], &mat2[j][2]);
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            res[i][j] = 0.0;
            for (int k = 0; k < COLS; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    printf("A x B\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%.2lf ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}
