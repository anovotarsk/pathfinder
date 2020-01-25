#include "../inc/pathfinder.h"

r_list *mx_create_edge(char *point1, char *point2, int len) {
    r_list *node = (r_list*)malloc(sizeof(r_list));

    node->point1 = point1;
    node->point2 = point2;
    node->len = len;
    node->next = NULL;
    return node;
}

void mx_push_edge(r_list **list, char *point1, char *point2, int len) {
    r_list *l = NULL;
    r_list *node = mx_create_edge(point1, point2, len);

    if (*list == NULL) {
        *list = node;
    }
    else {
        l = *list;
        while (l->next != NULL)
            l = l->next;
        l->next = node;
    }
}

t_path *mx_create_path(char *path, char *route) {
    t_path *node = (t_path*)malloc(sizeof(t_path));

    node->path = path;
    node->route = route;
    node->next = NULL;
    return node;
}

void mx_push_path(t_path **list, char *path, char *route) {
    t_path *l = NULL;
    t_path *node = mx_create_path(path, route);

    if (*list == NULL) {
        *list = node;
    }
    else {
        l = *list;
        while (l->next != NULL)
            l = l->next;
        l->next = node;
    }
}
