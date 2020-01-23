#include "../inc/pathfinder.h"

int mx_arr_size(char **arr) {
    int size = 0;

    while (arr[size] != NULL)
        size++;
    return size;
}

char *mx_arr_to_str(char **arr) {
    char *str = mx_strnew(0);
    char *tmp;
    int i = 0;

    while (arr[i] != NULL) {
        tmp = mx_strdup(str);
        mx_strdel(&str);
        str = mx_strcat(tmp, arr[i]);
        mx_strdel(&tmp);
        if (arr[i + 1] != NULL) {
            tmp = mx_strdup(str);
            mx_strdel(&str);
            str = mx_strcat(tmp, ",");
            mx_strdel(&tmp);
        }
        i++;
        printf("\n%s %s %s\n", arr[i], tmp, str);
        system("leaks -quiet a.out");
    }
    // free(arr);
    // arr = NULL;
    return str;
}

char *mx_fix(char *str, int index) {
    char **arr = mx_strsplit(str, ',');
    int size = mx_arr_size(arr);
    int i;

    for (i = 1; i < size; i++) {
        //printf("\n%d %s\n", index, arr[i]);
        if (mx_atoi(arr[i]) < index) {
            mx_strdel(&arr[0]);
            arr[0] = arr[i];
            mx_strdel(&arr[i]);
            arr[i] = mx_strdup("0");
            break;
        }
    }
    return mx_arr_to_str(arr);
}

void mx_check_matrix(char ***matrix, int count) {
    char *tmp;
    int i;
    int j;

    for (i = 0; i < count; i++) {
        for (j = 0; j < count; j++) {
            if (mx_strlen(matrix[i][j]) > 1 && matrix[i][j][0] == '0') {
                tmp = mx_fix(matrix[i][j], j);
                mx_strdel(&matrix[i][j]);
                matrix[i][j] = tmp;
                mx_strdel(&tmp);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    r_list *edges = NULL;
    p_list *points = NULL;

    mx_validator(argc, argv);
    mx_edges_list(&edges, argv[1]);
    points = mx_point_list(&edges, argv[1]);
    int **matrix = NULL;
    matrix = mx_adjacency_matrix(edges, points);
    int count = 4;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            if (matrix[i][j] != 0 && matrix[i][j] != 2147483647)
                printf("%d  ", matrix[i][j]);
            else
                printf("0  ");
        }
        printf("\n");
    }
    printf("\n\n\n");
    char ***m;
    m = mx_floyd(matrix, count, "");
    mx_check_matrix(m, count);
    printf("\n\n\n");
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            printf("%s  ", m[i][j]);
        }
        printf("\n");
    }
    system("leaks -quiet a.out");
}
