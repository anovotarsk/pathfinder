#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    char *str = (char*) s;
    size_t i;

    for (i = 0; i < n; i++) {
        if (*str == c)
            return str;
        str++;
    }
    return NULL;
}

/*#include <stdio.h>
int main() {
    char src[15]="1234567890";
    char *sym;
    sym = mx_memchr(src, 'x', 10);
    if (sym != NULL)
      sym[0]='!';
    printf ("%s\n",src);
    printf ("%s\n", sym);
}*/
