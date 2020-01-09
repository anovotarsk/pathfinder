#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    char buf;
    int count = 0, status, count_buf = 0;
    bool flag = true;
    while (flag) {
        for (size_t i = 0; i < buf_size; i++) {
            status = read(fd, &buf, 1);
            if (status == -1)
                return -1;
            if (status == 0)
                return 0;
            flag = (buf == delim) ? false : flag;
            if (buf == delim)
                return count;
            lineptr[0][i + count - count_buf] = buf;
            count++;
            count_buf++;
        }
        count_buf = 0;
    }
    return count;
}
