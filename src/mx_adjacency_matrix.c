#include "../inc/pathfinder.h"

int mx_get_index(p_list *points, char *s) {
    int index = -1;

    while (points != NULL) {
        index++;
        if (mx_strcmp(points->point, s) == 0)
            return index;
        points = points->next;
    }
    return -1;
}

char *mx_get_str(p_list *points, int index) {
    int i = 0;

    while (points != NULL) {
        if (i == index)
            return points->point;
        i++;
        points = points->next; 
    }
    return NULL;
}

static int count_of_points(p_list *points) {
    int count = 0;

    while (points != NULL) {
        count++;
        points = points->next;
    }
    return count;
}

int **mx_create_int_matrix(int count, int inf) {
    int **matrix = (int**)malloc(8 * count);
    int i;
    int j;

    for (i = 0; i < count; i++)
        matrix[i] = (int*)malloc(4 * count);
    for (i = 0; i < count; i++) {
        for (j = 0; j < count; j++) {
            if (i != j)
                matrix[i][j] = inf;
            else
                matrix [i][j] = 0;
        }
    }
    return matrix;
}

int **mx_adjacency_matrix(r_list *edges, p_list *points) {
    int count = count_of_points(points);
    int **matrix = mx_create_int_matrix(count, 2147483647);

    while (edges != NULL) {
        matrix[mx_get_index(points, edges->point1)]
        [mx_get_index(points, edges->point2)] = edges->len;
        matrix[mx_get_index(points, edges->point2)]
        [mx_get_index(points, edges->point1)] = edges->len;
        edges = edges->next;
    }
    return matrix;
}
