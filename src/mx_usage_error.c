#include "../inc/pathfinder.h"

void mx_usage_error(int argc) {
    char *error = "usage: ./pathfinder [filename]\n";

    if (argc != 2) {
        write(2, error, mx_strlen(error));
        exit(0);
    }
}
