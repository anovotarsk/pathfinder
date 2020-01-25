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
    }
    return str;
}

char *mx_fix(char *str, int index) {
    char **arr = mx_strsplit(str, ',');
    char *s;
    int size = mx_arr_size(arr);
    int i;

    for (i = 1; i < size; i++) {
        if (mx_atoi(arr[i]) < index) {
            mx_strdel(&arr[0]);
            arr[0] = mx_strdup(arr[i]);
            mx_strdel(&arr[i]);
            arr[i] = mx_strdup("0");
            break;
        }
    }
    s = mx_arr_to_str(arr);
    mx_del_strarr(&arr);
    return s;
}

void mx_symmetric_matrix(char ***matrix, int count) {
    char *tmp;
    int i;
    int j;

    for (i = 0; i < count; i++) {
        for (j = 0; j < count; j++) {
            if (j - i > 0) {
                tmp = mx_strdup(matrix[i][j]);
                mx_strdel(&matrix[j][i]);
                matrix[j][i] = mx_strdup(tmp);
                mx_strdel(&tmp);
            }
        }
    }
}

void mx_check_matrix(char ***matrix, int count) {
    char *tmp;
    int i;
    int j;
    bool flag = false;

    for (i = 0; i < count; i++) {
        for (j = 0; j < count; j++) {
            if (mx_strlen(matrix[i][j]) > 1 && matrix[i][j][0] == '0'
                && j - i >= 0) {
                flag = true;
                tmp = mx_fix(matrix[i][j], j);
                mx_strdel(&matrix[i][j]);
                matrix[i][j] = mx_strdup(tmp);
                mx_strdel(&tmp);
            }
        }
    }
    if (flag)
        mx_symmetric_matrix(matrix, count);
}
