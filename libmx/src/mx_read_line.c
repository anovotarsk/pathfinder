#include "libmx.h"

int mx_read_line(char **lineptr, char delim, const int fd) {
    char buf;
    int count = 0, status;
    bool flag = true;
    while (flag) {
        status = read(fd, &buf, 1);
        if (status == -1)
            return -1;
        if (status == 0)
            return 0;
        flag = (buf == delim) ? false : flag;
        if (buf == delim)
            return count;
        lineptr[0][count] = buf;
        count++;
    }
    return count;
}
