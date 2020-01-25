#include "../inc/pathfinder.h"

int main(int argc, char *argv[]) {
    r_list *edges = NULL;
    p_list *points = NULL;
    int **matrix = NULL;
    char ***m;
    int count = 49;

    mx_validator(argc, argv);
    mx_edges_list(&edges, argv[1]);
    points = mx_point_list(&edges, argv[1]);
    matrix = mx_adjacency_matrix(edges, points);
    m = mx_floyd(matrix, count);
    mx_check_matrix(m, count);
    t_path ***l = NULL;
    l = mx_create_path_matrix(m, count);
    t_path ***l1 = l;
    //printf("%s\n", mx_itoa(54));
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            if (j - i > 0) {
                t_path *list = l1[i][j];
                while (list != NULL) {
                    //printf("%d %d\n", i, j);
                    mx_print_pathes(list, points, matrix);
                    //printf("Path: %s\nRoute: %s\n========\n", list->path, list->route);
                    list = list->next;
                }
            }
        }
    }
    //system("leaks -quiet a.out");
}
