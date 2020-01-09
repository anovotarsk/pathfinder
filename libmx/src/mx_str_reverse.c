#include "libmx.h"

void mx_str_reverse(char *s) {
    int len;
    int i = 0;

    if (s == NULL)
        return;
    len = mx_strlen(s) - 1;
    while (len != i && len > i) {
        mx_swap_char(&s[i], &s[len]);
        i++;
        len--;
    }
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char str[10] = "game over";
    char *s = "game over";
    strrev(str);
    printf("%s\n", s);
    mx_str_reverse(str);
    printf("%s", str);
}*/
