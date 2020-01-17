#include "../inc/pathfinder.h"

static void mx_error_line(int line) {
    char *error1 = "error: line ";
    char *error2 = " is not valid\n";
    char *l = mx_itoa(line);

    write(2, error1, mx_strlen(error1));
    write(2, l, mx_strlen(l));
    write(2, error2, mx_strlen(error2));
    exit(1);
}

static void mx_delimeters(char *s, int line) {
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
        mx_error_line(line);
}

static void mx_line_parsing(r_list **list, char *s, int line) {
    char **l1;
    char **l2;

    mx_delimeters(s, line);
    if (s[0] == '\0')
        mx_error_line(line);
    l1 = mx_strsplit(s, '-');
    if (mx_isalphabetic(l1[0]) == false || l1[1] == NULL)
        mx_error_line(line);
    l2 = mx_strsplit(l1[1], ',');
    if (mx_isalphabetic(l2[0]) == false || l2[1] == NULL
        || mx_atoi(l2[1]) == -1)
        mx_error_line(line);
    mx_push_edge(&(*list), l1[0], l2[0], mx_atoi(l2[1]));
    mx_strdel(&l1[1]);
    mx_strdel(&l2[1]);
}

void mx_edges_list(r_list **list, char *file) {
    int fd = open(file, O_RDONLY);
    int line = 1;
    char *s = mx_read_line('\n', fd);

    mx_strdel(&s);
    s = mx_read_line('\n', fd);
    line++;
    while (s != NULL) {
        mx_line_parsing(&(*list), s, line);
        mx_strdel(&s);
        s = mx_read_line('\n', fd);
        line++;
    }
}
