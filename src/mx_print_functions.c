#include "../inc/pathfinder.h"

void mx_print_line() {
    write(1, "========================================\n", 41);
}

void mx_print_path(char *point1, char *point2) {
    mx_printstr("Path: ");
    mx_printstr(point1);
    mx_printstr(" -> ");
    mx_printstr(point2);
    mx_printchar('\n');
}

void mx_print_route(char **arr) {
    mx_printstr("Route: ");
    mx_print_strarr(arr, " -> ");
}

void mx_print_distance(char **arr) {
    mx_printstr("Distance: ");
    mx_print_strarr(arr, " -> ");
}
