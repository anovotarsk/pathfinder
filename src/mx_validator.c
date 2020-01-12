#include "../inc/pathfinder.h"

void mx_validator(int argc, char *argv[]) {
    mx_usage_error(argc);
    mx_exist_error(argv[1]);
    mx_empty_error(argv[1]);
    mx_line1_error(argv[1]);
}
