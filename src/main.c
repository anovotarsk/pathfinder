#include "../inc/pathfinder.h"

int main(int argc, char *argv[]) {
    r_list *edges = NULL;
    char **points = NULL;

    mx_validator(argc, argv);
    mx_edges_list(&edges, argv[1]);
    mx_point_array(&points, edges, argv[1]);
    system("leaks -quiet a.out");
}
