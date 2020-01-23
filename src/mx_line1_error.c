#include "../inc/pathfinder.h"

int mx_line1_error(char *file) {
    int fd = open(file, O_RDONLY);
    int islands;
    char *line = mx_read_line('\n', fd);

    close(fd);
    if (line == NULL) {
        write(2, "error: line 1 is not valid\n", 27);
        exit(0);
    }
    islands = mx_atoi(line);
    mx_strdel(&line);
    if (islands == -1) {
        write(2, "error: line 1 is not valid\n", 27);
        exit(0);
    }
    return islands;
}
