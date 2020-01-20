#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"

typedef struct edge {
    char *point1;
    char *point2;
    int len;
    struct edge *next;
} r_list;

typedef struct p_list {
    char *point;
    struct p_list *next;
} p_list;

//lists
r_list *mx_create_edge(char *point1, char *point2, int len);
void mx_push_edge(r_list **list, char *point1, char *point2, int len);
void mx_edges_list(r_list **list, char *file);

p_list *mx_create_point(char *data);
void mx_push_point(p_list **list, char *point);
int mx_get_index(p_list *points, char *s);
char *mx_get_str(p_list *points, int index);

//useful functions
int mx_atoi(char *str);
bool mx_isalphabetic(char *str);

//matrix
int **mx_adjacency_matrix(r_list *edges, p_list *points);
int **mx_create_int_matrix(int count, int inf);

//error cases
void mx_usage_error(int argc);
void mx_exist_error(char *file);
void mx_empty_error(char *file);
int mx_line1_error(char *file);
p_list *mx_point_list(r_list **edges, char *file);
void mx_validator(int argc, char *argv[]);

void mx_floyd(int **adjacency, int count);

#endif
