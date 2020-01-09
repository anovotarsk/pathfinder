#include "../inc/pathfinder.h"

void mx_exist_error(char *file) {
    char *error1 = "error: file ";
    char *error2 = " does not exist\n";
    int fd = open(file, O_RDONLY);

    if (fd == -1) {
        write(2, error1, mx_strlen(error1));
        write(2, file, mx_strlen(file));
        write(2, error2, mx_strlen(error2));
        exit(0);
    }
    close(fd);
}
