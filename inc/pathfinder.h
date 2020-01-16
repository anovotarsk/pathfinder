#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"

typedef struct edge {
    void *point1;
    void *point2;
    int len;
    struct edge *next;
} r_list;

//lists
r_list *mx_create_edge(void *point1, void *point2, int len);
void mx_push_edge(r_list **list, void *point1, void *point2, int len);
void mx_edges_list(r_list **list, char *file);

//useful functions
int mx_atoi(char *str);
bool mx_isalphabetic(char *str);

//error cases
void mx_usage_error(int argc);
void mx_exist_error(char *file);
void mx_empty_error(char *file);
int mx_line1_error(char *file);
void mx_point_array(char ***arr, r_list *list, char *file);

void mx_validator(int argc, char *argv[]);

#endif
