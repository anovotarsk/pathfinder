#include "../inc/pathfinder.h"

void mx_print_strarr_of_node(char **arr, const char *delim, p_list *node_for_print) {
    int len_arr = 0;
    int i;

    if (!arr || !delim)
        return;
    while (arr[len_arr] != NULL)
        len_arr++;
    if (len_arr == 0)
        return;
    for (i = 0; i < len_arr; i++) {
        mx_printstr(mx_get_str(node_for_print, mx_atoi(arr[i]) - 1));
        if (i < len_arr - 1)
            mx_printstr(delim);
    }
    mx_printstr("\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
static char *many_path(char **splited_route, int **sizes, char *str_of_dist, int size);
static char *one_path(char **splited_route, int **sizes) ;

char *mx_create_dist_str(char **splited_route, int **sizes, char *str_of_dist) {
    int size = mx_arr_size(splited_route);
    char *result;

    if (size > 2)
        result = many_path(splited_route, sizes, str_of_dist, size);
    else 
        result = one_path(splited_route, sizes);
    return result;
}

static char *one_path(char **splited_route, int **sizes) {
    int count = 0;
    char *itoa_help;

    count = sizes[atoi(splited_route[0]) - 1][atoi(splited_route[1]) - 1];
    if (sizes[atoi(splited_route[0]) - 1][atoi(splited_route[1]) - 1] == 2147483647)
        return NULL;
    itoa_help = mx_itoa(count);
    return itoa_help;
}

static char *many_path(char **splited_route, int **sizes, char *str_of_dist, int size) {
    int i;
    char *help_str;
    char *itoa_help;
    int sum = 0;
    int count = 0;

    for (i = 0; i < size - 1; i++) {
        count = sizes[atoi(splited_route[i]) - 1][atoi(splited_route[i + 1]) - 1];
        if (count == 2147483647)
            return NULL;
        sum += count;
        itoa_help = mx_itoa(count);
        help_str = mx_strcat(str_of_dist, itoa_help);
        mx_strdel(&itoa_help);
        mx_strdel(&str_of_dist);
        if (i != size -2)
            str_of_dist = mx_strcat(help_str, " + ");
        else
            str_of_dist = mx_strcat(help_str, " = ");
        mx_strdel(&help_str);
    }
    mx_strdel(&help_str);
    itoa_help = mx_itoa(count);
    help_str = mx_strcat(str_of_dist, itoa_help);
    mx_strdel(&itoa_help);
    mx_strdel(&str_of_dist);
    return help_str;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mx_print_node(t_path *printed_node, p_list *list_of_islands, int **sizes) {
    char **splited_path;
    char **splited_route;
    char *str_of_dist = mx_strnew(10);

    splited_path = mx_strsplit(printed_node->path, ',');
    splited_route = mx_strsplit(printed_node->route, ',');
    str_of_dist = mx_create_dist_str(splited_route, sizes, str_of_dist);
    if (str_of_dist ==  NULL)
        return;
    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_print_strarr_of_node(splited_path, " -> ", list_of_islands);
    mx_printstr("Route: ");
    mx_print_strarr_of_node(splited_route, " -> ", list_of_islands);
    mx_printstr("Distance: ");
    mx_printstr(str_of_dist);
    mx_strdel(&str_of_dist);
    mx_printstr("\n");
    mx_printstr("========================================\n");
    mx_del_strarr(&splited_path);
    mx_del_strarr(&splited_route);
}

void mx_print_nodes(t_path *printed_node, p_list *list_of_islands, int **sizes) {
     while (printed_node != NULL) {
        mx_print_node(printed_node, list_of_islands, sizes);
        printed_node = printed_node->next;
     }
}
