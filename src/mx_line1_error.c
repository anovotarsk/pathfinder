#include "../inc/pathfinder.h"

int mx_line1_error(char *file) {
    int fd = open(file, O_RDONLY);
    char *line = mx_strnew(10000);
    int islands;

    mx_read_line(&line, '\n', fd);
    close(fd);
    islands = mx_atoi(line);
    mx_strdel(&line);
    if (islands == -1) {
        write(2, "error: line 1 is not valid\n", 27);
        exit(0);
    }
    return islands;
}
