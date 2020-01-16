#include "libmx.h"

char *mx_read_line(char delim, const int fd) {
    static bool end_flag = false;
    char buf;
    int status;
    char *s = mx_strnew(0);
    int len = 0;

    while (true) {
        status = read(fd, &buf, 1);
        if (status == -1 || (status == 0 && end_flag == true)) {
            mx_strdel(&s);
            return NULL;
        }
        if (buf == delim || (status == 0 && end_flag == false)) {
            end_flag = (status == 0) ? true : false;
            s = mx_realloc(s, ++len);
            s[len - 1] = '\0';
            return s;
        }
        s = mx_realloc(s, ++len);
        s[len - 1] = buf;
    }
    return NULL;
}
