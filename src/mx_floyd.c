#include "../inc/pathfinder.h"

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

char ***mx_floyd(int **sh, int count) {
    char *tmp;
    char ***path = mx_create_char_matrix(count);

    for (int k = 0; k < count; k++) {
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < count; j++) {
                if (sh[i][k] + sh[k][j] <= sh[i][j] 
                    && sh[i][k] + sh[k][j] >= 0 && k != j && k!= i) {
                    if (sh[i][k] + sh[k][j] != sh[i][j]) {
                        mx_strdel(&path[i][j]);
                        path[i][j] = mx_strnew(0);
                    }
                    else {
                        tmp = mx_strdup(path[i][j]);
                        mx_strdel(&path[i][j]);
                        path[i][j] = mx_strcat(tmp, ",");
                        mx_strdel(&tmp);
                    }
                    path[i][j] = mx_strcat_del(path[i][j], mx_itoa(k), "");
                    sh[i][j] = sh[i][k] + sh[k][j];
                }
            }
        }
    }
    return path;
}
