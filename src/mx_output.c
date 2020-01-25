#include "../inc/pathfinder.h"

static bool check_path(char *str, int **matrix) {
    char **arr = mx_strsplit(str, ',');
    int i = 0;
    char *s1;
    char *s2;

    while (arr[i + 1] != NULL) {
        s1 = mx_strdup(arr[i]);
        s2 = mx_strdup(arr[i + 1]);
        //printf("%s %s\n", s1, s2);
        //mx_str_reverse(s1);
        //mx_str_reverse(s2);
        if (matrix[mx_atoi(s1)][mx_atoi(s2)] == 2147483647) {
            mx_del_strarr(&arr);
            mx_strdel(&s1);
            mx_strdel(&s2);
            return false;
        }
        i++;
    }
    mx_strdel(&s1);
    mx_strdel(&s2);
    mx_del_strarr(&arr);
    return true;
}

static void points_arr(char **arr, p_list *points) {
    char *tmp;
    int i = 0;

    while (arr[i] != NULL) {
        tmp = arr[i];
        arr[i] = mx_strdup(mx_get_str(points, mx_atoi(tmp)));
        mx_strdel(&tmp);
        i++;
    }
}

char **distance_arr(char **route, int **matrix) {
    int len = mx_arr_size(route) - 1;
    char **arr = (char **)malloc(sizeof(char*) * (len + 1));
    int i;

    arr[len] = NULL;
    for (i =0; i < len; i++) {
        arr[i] = mx_itoa(matrix[mx_atoi(route[i])][mx_atoi(route[i + 1])]);
    }
    return arr;
}

static void print(char **path, char **route, char **distance) {
    mx_print_line();
    mx_print_path(path[0], path[1]);
    mx_print_route(route);
    mx_print_distance(distance);
    mx_print_line();
}

void mx_print_pathes(t_path *list, p_list *points, int **matrix) {
    char **path;
    char **route;
    char **distance;

    if (check_path(list->route, matrix) == false)
        return;
    path = mx_strsplit(list->path, ',');
    route = mx_strsplit(list->route, ',');
    distance = distance_arr(route, matrix);
    points_arr(path, points);
    points_arr(route, points);
    print(path, route, distance);
    mx_del_strarr(&path);
    mx_del_strarr(&route);
    mx_del_strarr(&distance);
}
