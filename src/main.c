#include "../inc/pathfinder.h"

int main(int argc, char *argv[]) {
    r_list *edges = NULL;
    p_list *points = NULL;

    mx_validator(argc, argv);
    mx_edges_list(&edges, argv[1]);
    r_list *e = edges;
    while (e != NULL) {
        printf("%s %s %d\n", e->point1, e->point2, e->len);//agehhaerperahi
        e = e->next;
    }
    //printf("%d\n", mx_strcmp(edges->point2, edges->next->point1));
    points = mx_point_list(&edges, argv[1]);
    while (points != NULL) {
        printf("%s\n", points->point);
        points = points->next;
    }
    system("leaks -quiet a.out");
}
