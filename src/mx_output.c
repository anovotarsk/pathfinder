#include "../inc/pathfinder.h"

void mx_recursion(t_path **list, char ***pathes, int i, int j, char *str) {
    char *tmp = mx_strdup(str);
    char **arr = mx_strsplit(pathes[i][j], ',');
    int k = 0;

    str = mx_strcat_del(tmp, mx_itoa(j), ",");
    while (arr[k] != NULL) {
        if (mx_strcmp(arr[k], "0") == 0) {
            str = mx_strcat_del(str, mx_itoa(i), ",");
            mx_del_strarr(&arr);
            mx_str_reverse(str);
            mx_push_path(&(*list), NULL, str);
            return;
        }
        mx_recursion(list, pathes, i, mx_atoi(arr[k]), str);
        k++;
    }
    mx_del_strarr(&arr);
    mx_strdel(&str);
}

t_path *mx_create_path_list(char ***pathes, int i, int j) {
    t_path *list = NULL;

    mx_recursion(&list, pathes, i, j, "");
    return list;
}
