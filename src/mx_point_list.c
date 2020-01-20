#include "../inc/pathfinder.h"

p_list *mx_create_point(char *data) {
    p_list *node = (p_list*)malloc(sizeof(p_list));

    node->point = data;
    node->next = NULL;
    return node;
}

static void add_to_list(p_list **list, char *s) {
    p_list *l = NULL;

    if (*list == NULL)
        *list = mx_create_point(s);
    else {
        l = *list;
        while (l->next != NULL) {
            if (mx_strcmp(l->point, s) == 0)
                return;
            l = l->next;
        }
        if (mx_strcmp(l->point, s) == 0)
            return;
        l->next = mx_create_point(s);;
    }
}

static void mx_count_error(char *file, p_list *points) {
    int fd = open(file, O_RDONLY);
    char *line = mx_read_line('\n', fd);
    int len = mx_atoi(line);
    int count = 0;

    mx_strdel(&line);
    close(fd);
    while (points != NULL) {
        count++;
        points = points->next;
    }
    if (len != count) {
        write(2, "error: invalid number of islands\n", 33);
        exit(1);
    }
}

p_list *mx_point_list(r_list **edges, char *file) {
    r_list *e = *edges;
    p_list *points = NULL;

    while (e != NULL) {
        add_to_list(&points, e->point1);
        add_to_list(&points, e->point2);
        e = e->next;
    }
    mx_count_error(file, points);
    return points;
}
