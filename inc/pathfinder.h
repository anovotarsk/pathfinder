#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"

//useful functions
int mx_atoi(char *str);

//error cases
void mx_usage_error(int argc);
void mx_exist_error(char *file);
void mx_empty_error(char *file);

#endif
