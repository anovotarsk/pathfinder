#include "../inc/pathfinder.h"

r_list *mx_create_edge(void *point1, void *point2, int len) {
    r_list *node = (r_list*)malloc(sizeof(r_list));

    node->point1 = point1;
    node->point2 = point2;
    node->len = len;
    node->next = NULL;
    return node;
}

void mx_push_edge(r_list **list, void *point1, void *point2, int len) {
    r_list *l = NULL;
    r_list *node = mx_create_edge(point1, point2, len);

    if (list == NULL)
        list = &node;
    if (*list == NULL)
        *list = node;
    else {
        l = *list;
        while (l->next != NULL)
            l = l->next;
        l->next = node;
    }
}
