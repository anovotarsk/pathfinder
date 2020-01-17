#include "../inc/pathfinder.h"

p_list *mx_create_point(char *data) {
    p_list *node = (p_list*)malloc(sizeof(p_list));

    node->point = data;
    node->next = NULL;
    return node;
}

void mx_push_point(p_list **list, char *point) {
    p_list *l = NULL;
    p_list *node = mx_create_point(point);

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

static void add_to_list(p_list **list, char *s) {
    p_list *l = NULL;
    p_list *node = mx_create_point(s);

    if (*list == NULL)
        *list = node;
    else {
        l = *list;
        while (l->next != NULL) {
            printf("%s %s %d\n", s, l->point, mx_strcmp(s, l->point));//agponv
            if (mx_strcmp(l->point, s) == 0)
                return;
            l = l->next;
        }
        l->next = node;
    }
}

p_list *mx_point_list(r_list **edges, char *file) {
    r_list *e = *edges;
    p_list *points = NULL;
    int fd = open(file, O_RDONLY);
    //int len = mx_atoi(mx_read_line('\n', fd));
    //int count = 0;

    close(fd);
    while (e != NULL) {
        add_to_list(&points, e->point1);
        add_to_list(&points, e->point2);
        e = e->next;
    }
    // while (points != NULL) {
    //     count++;
    //     points = points->next;
    // }
    // if (len != count) {
    //     write(2, "error\n", 6);
    //     exit(1);
    // }
    return points;
}
