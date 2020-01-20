#include "../inc/pathfinder.h"

static void error_line(int line) {
    char *error1 = "error: line ";
    char *error2 = " is not valid\n";
    char *l = mx_itoa(line);

    write(2, error1, mx_strlen(error1));
    write(2, l, mx_strlen(l));
    write(2, error2, mx_strlen(error2));
    exit(1);
}

static void delimeters(char *s, int line) {
    int count1 = 0;
    int count2 = 0;
    int i;

    for (i = 0; i < mx_strlen(s); i++) {
        if (s[i] == '-')
            count1++;
        if (s[i] == ',')
            count2++;
    }
    if (count1 != 1 || count2 != 1)
        error_line(line);
}

static void line_parsing(r_list **list, char *s, int line) {
    char **l1;
    char **l2;

    delimeters(s, line);
    if (s[0] == '\0')
        error_line(line);
    l1 = mx_strsplit(s, '-');
    if (mx_isalphabetic(l1[0]) == false || l1[1] == NULL)
        error_line(line);
    l2 = mx_strsplit(l1[1], ',');
    if (mx_isalphabetic(l2[0]) == false || l2[1] == NULL
        || mx_atoi(l2[1]) == -1)
        error_line(line);
    mx_push_edge(&(*list), mx_strdup(l1[0]),
    mx_strdup(l2[0]), mx_atoi(l2[1]));
    mx_del_strarr(&l1);
    mx_del_strarr(&l2);
}

static void lastline_error(char *file, int line) {
    char *f = mx_file_to_str(file);

    if (f[mx_strlen(f) - 1] != '\n')
        error_line(line);
    mx_strdel(&f);
}

void mx_edges_list(r_list **list, char *file) {
    int fd = open(file, O_RDONLY);
    int line = 1;
    char *s = mx_read_line('\n', fd);

    mx_strdel(&s);
    s = mx_read_line('\n', fd);
    line++;
    while (s != NULL) {
        line_parsing(&(*list), s, line);
        mx_strdel(&s);
        s = mx_read_line('\n', fd);
        line++;
    }
    close(fd);
    lastline_error(file, line);
}
