#include "../inc/pathfinder.h"

static void mx_count_error() {
    write(2, "error: invalid number of islands\n", 33);
    exit(1);
}

static bool mx_is_in_arr(char **arr, int len, char *s) {
    int i;

    for (i = 0; i < len; i++) {
        if (arr[i] == s)
            return true;
    }
    return false;
}

void mx_point_array(char ***arr, r_list *list, char *file) {
    int fd = open(file, O_RDONLY);
    int len = mx_atoi(mx_read_line('\n', fd));
    int count = 0;

    close(fd);
    *arr = (char**)malloc(8 * len);
    while (list != NULL) {
        if (count >= len)
            mx_count_error();
        if (mx_is_in_arr(*arr, len, list->point1) != true)
            *arr[count++] = list->point1;
        if (mx_is_in_arr(*arr, len, list->point2) != true)
            *arr[count++] = list->point2;
        list = list->next;
    }
    if (count < len)
            mx_count_error();
}
