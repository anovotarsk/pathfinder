#include "libmx.h"

void mx_strdel(char **str) {
    free(*str);
    *str = NULL;
}

/*#include <stdio.h>
int main() {

    char *s = malloc(4);
    s[0] = 'l';
    s[1] = 'o';
    s[2] = 'l';
    s[3] = '\0';
    printf("%s", s);

    mx_strdel(&s);
    printf("%s", s);
}*/
