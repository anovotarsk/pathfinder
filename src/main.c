#include "../inc/pathfinder.h"

int main(int argc, char *argv[]) {
    r_list *edges = NULL;
    p_list *points = NULL;

    mx_validator(argc, argv);
    mx_edges_list(&edges, argv[1]);
    points = mx_point_list(&edges, argv[1]);
    int **matrix = NULL;
    matrix = mx_adjacency_matrix(edges, points);
    int count = 5;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            if (matrix[i][j] != 0 && matrix[i][j] != 2147483647)
                printf("%d  ", matrix[i][j]);
            else
                printf("0  ");
        }
        printf("\n");
    }
    printf("\n\n\n");
    char ***m;
    m = mx_floyd(matrix, count);
    //system("leaks -quiet a.out");
}
