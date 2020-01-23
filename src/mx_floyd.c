#include "../inc/pathfinder.h"

// static int **copy_matrix(int **matrix, int count) {
//     int **new_m = (int**)malloc(8 * count);
//     int i;
//     int j;

//     for (i = 0; i < count; i++)
//         new_m[i] = (int*)malloc(4 * count);
//     for (i = 0; i < count; i++) {
//         for (j = 0; j < count; j++) {
//             new_m[i][j] = matrix[i][j];
//         }
//     }
//     return new_m;
// }

char ***mx_create_char_matrix(int count) {
    char ***matrix = (char***)malloc(sizeof(char**) * count);
    int i;
    int j;

    for (i = 0; i < count; i++)
        matrix[i] = (char**)malloc(8 * count);
    for (i = 0; i < count; i++)
        for (j = 0; j < count; j++) {
            matrix[i][j] = mx_strnew(1);
            matrix[i][j][0] = '0';
        }
    return matrix;
}

char ***mx_floyd(int **shortest, int count, char *t) {
    char *tmp;
    char ***pathes = mx_create_char_matrix(count);

    for (int k = 0; k < count; k++) {
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < count; j++) {
                if (shortest[i][k] + shortest[k][j] <= shortest[i][j] 
                    && shortest[i][k] + shortest[k][j] >= 0
                    && k != j && k!= i) {
                    if (shortest[i][k] + shortest[k][j] != shortest[i][j]) {
                        mx_strdel(&pathes[i][j]);
                        pathes[i][j] = mx_strnew(0);
                    }
                    else {
                        tmp = mx_strdup(pathes[i][j]);
                        mx_strdel(&pathes[i][j]);
                        pathes[i][j] = mx_strcat(tmp, ",");
                        mx_strdel(&tmp);
                    }
                    tmp = mx_strdup(pathes[i][j]);
                    mx_strdel(&pathes[i][j]);
                    t = mx_itoa(k);
                    pathes[i][j] = mx_strcat(tmp, t);
                    mx_strdel(&t);
                    shortest[i][j] = shortest[i][k] + shortest[k][j];
                    mx_strdel(&tmp);
                }
            }
        }
    }
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            printf("%d  ", shortest[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            printf("%s  ", pathes[i][j]);
        }
        printf("\n");
    }
    return pathes;
}
