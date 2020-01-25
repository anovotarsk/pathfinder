#include "../inc/pathfinder.h"

void mx_print_line() {
    write(1, "========================================\n", 41);
}

void mx_print_path(char *point1, char *point2) {
    mx_printstr("Path: ");
    mx_printstr(point2);
    mx_printstr(" -> ");
    mx_printstr(point1);
    mx_printchar('\n');
}

void mx_print_route(char **arr) {
    int len = mx_arr_size(arr);

    mx_printstr("Route: ");
    while (len != 0) {
        mx_printstr(arr[len - 1]);
        if (len - 1 > 0)
            mx_printstr(" -> ");
        len--;
    }
    mx_printchar('\n');
}

static void print_end(int count) {
    char *s = mx_itoa(count);

    mx_printstr(s);
    mx_printchar('\n');
    mx_strdel(&s);
}
void mx_print_distance(char **arr) {
    int i = mx_arr_size(arr);
    int count = 0;

    mx_printstr("Distance: ");
    if (arr[1] == NULL) {
        mx_printstr(arr[0]);
        mx_printchar('\n');
        return;
    }
    while (i > 0) {
        mx_printstr(arr[i - 1]);
        mx_printstr((i - 1 != 0) ? " + " : " = ");
        count += mx_atoi(arr[i - 1]);
        i--;
    }
    print_end(count);
}
