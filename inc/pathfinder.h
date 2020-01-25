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

typedef struct s_path {
    char *path;
    char *route;
    struct s_path *next;
} t_path;

//lists
r_list *mx_create_edge(char *point1, char *point2, int len);
void mx_push_edge(r_list **list, char *point1, char *point2, int len);
void mx_edges_list(r_list **list, char *file);

p_list *mx_create_point(char *data);
void mx_push_point(p_list **list, char *point);
int mx_get_index(p_list *points, char *s);
char *mx_get_str(p_list *points, int index);

t_path *mx_create_path(char *path, char *route);
void mx_push_path(t_path **list, char *path, char *route);

//useful functions
int mx_atoi(char *str);
bool mx_isalphabetic(char *str);
char *mx_strcat_del(char *s1, char *s2, char *del);

//matrix
int **mx_adjacency_matrix(r_list *edges, p_list *points);
int **mx_create_int_matrix(int count, int inf);
int mx_arr_size(char **arr);
char *mx_arr_to_str(char **arr);
char *mx_fix(char *str, int index);
void mx_check_matrix(char ***matrix, int count);

t_path ***mx_create_path_matrix(char ***pathes, int count);

//error cases
void mx_usage_error(int argc);
void mx_exist_error(char *file);
void mx_empty_error(char *file);
int mx_line1_error(char *file);
p_list *mx_point_list(r_list **edges, char *file);
void mx_validator(int argc, char *argv[]);

char ***mx_floyd(int **adjacency, int count);

//print functions
void mx_print_line();
void mx_print_path(char *point1, char *point2);
void mx_print_route(char **arr);
void mx_print_distance(char **arr);

void mx_pathes(char ***pathes, int count, p_list *points);

void mx_print_pathes(t_path *list, p_list *points, int **matrix);


#endif
