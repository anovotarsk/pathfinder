#include "../inc/pathfinder.h"

static int **copy_matrix(int **matrix, int count) {
    int **new_m = (int**)malloc(8 * count);
    int i;
    int j;

    for (i = 0; i < count; i++)
        new_m[i] = (int*)malloc(4 * count);
    for (i = 0; i < count; i++) {
        for (j = 0; j < count; j++) {
            new_m[i][j] = matrix[i][j];
        }
    }
    return new_m;
}

void mx_floyd(int **adjacency, int count) {
    int **shortest = copy_matrix(adjacency, count);
    int **pathes = mx_create_int_matrix(count, 0);
    int i;
    int j;
    int k;

    for (k = 0; k < count; k++) {
        for (i = 0; i < count; i++) {
            for (j = 0; j < count; j++) {
                if (shortest[i][k] + shortest[k][j] < shortest[i][j] 
                    && shortest[i][k] + shortest[k][j] >= 0) {
                    shortest[i][j] = shortest[i][k] + shortest[k][j];
                    pathes[i][j] = k + 1;
                }
            }
        }
    }
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            if (shortest[i][j] != 0 && shortest[i][j] != 2147483647)
                printf("%d  ", shortest[i][j]);
            else
                printf("0  ");
        }
        printf("\n");
    }
    printf("\n\n\n");
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            if (pathes[i][j] != 0 && pathes[i][j] != 2147483647)
                printf("%d  ", pathes[i][j]);
            else
                printf("0  ");
        }
        printf("\n");
    }
}
