#include "../inc/pathfinder.h"



static void mx_recursion(t_path **list, char ***pathes, int i, int j, char *str) {
    char *tmp = mx_strdup(str);
    char **arr = mx_strsplit(pathes[i][j], ',');
    int k = 0;

    str = mx_strcat_del(tmp, mx_itoa(j), ",");
    while (arr[k] != NULL) {
        if (mx_strcmp(arr[k], "0") == 0) {
            str = mx_strcat_del(str, mx_itoa(i), ",");
            mx_del_strarr(&arr);
            mx_push_path(&(*list), NULL, str);
            return;
        }
        mx_recursion(list, pathes, i, mx_atoi(arr[k]), str);
        k++;
    }
    mx_del_strarr(&arr);
    mx_strdel(&str);
}

static t_path *mx_create_path_list(char ***pathes, int i, int j) {
    t_path *list = NULL;
    t_path *l = NULL;
    char **arr;
    int len;

    mx_recursion(&list, pathes, i, j, "");
    l = list;
    while (l != NULL) {
        arr = mx_strsplit(l->route, ',');
        len = mx_arr_size(arr);
        l->path = mx_strcat_del(mx_strdup(arr[0]), mx_strdup(arr[len - 1]), ",");
        mx_del_strarr(&arr);
        l = l->next;
    }
    return list;
}

static t_path ***mx_create_list_matrix(int count) {
    t_path ***matrix = (t_path***)malloc(sizeof(t_path**) * count);
    int i;
    int j;

    for (i = 0; i < count; i++)
        matrix[i] = (t_path**)malloc(sizeof(t_path*) * count);
    for (i = 0; i < count; i++)
        for (j = 0; j < count; j++) {
            matrix[i][j] = NULL;
        }
    return matrix;
}

t_path ***mx_create_path_matrix(char ***pathes, int count) {
    t_path ***matrix = mx_create_list_matrix(count);
    int i;
    int j;

    for (i = 0; i < count; i++) {
        for (j = 0; j < count; j++) {
            if (j - i > 0)
                matrix[i][j] = mx_create_path_list(pathes, i, j);
        }
    }
    return matrix;
}
