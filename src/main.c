#include "../inc/pathfinder.h"

int main(int argc, char *argv[]) {
    r_list *edges = NULL;
    p_list *points = NULL;
    int **matrix = NULL;
    char ***m;
    int count = 7;

    mx_validator(argc, argv);
    mx_edges_list(&edges, argv[1]);
    points = mx_point_list(&edges, argv[1]);
    matrix = mx_adjacency_matrix(edges, points);
    m = mx_floyd(matrix, count);
    mx_check_matrix(m, count);
    // t_path *l = NULL;
    // l = mx_create_path_list(m, 0, 3);
    // t_path *list = l;
    // if (list == NULL)
    //     printf("\n NULL\n");
    // while (list != NULL) {
    //     printf("%s %s\n", list->path, list->route);
    //     list = list->next;
    //
    t_path *test_list = mx_create_path("1,4", "1,2,4");
    mx_push_path(&test_list, "2,4", "2,4");
    mx_push_path(&test_list, "2,4", "2,3,4");
    mx_push_path(&test_list, "2,4", "2,3,4");
    mx_push_path(&test_list, "2,4", "2,3,4");
    mx_push_path(&test_list, "2,4", "2,3,4");
    mx_push_path(&test_list, "2,4", "2,3,4");
    mx_push_path(&test_list, "5,6", "5,6");
    mx_print_nodes(test_list, points, matrix);
    system("leaks -quiet a.out");
}
