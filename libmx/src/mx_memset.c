#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    char *p = (char *) b;

    while (len-- > 0)
        *p++ = c;
    return b;
}

/*char *mx_strnew(const int size);
#include <stdio.h>
#include <string.h>
int main() {
    char c[] = "qwertyuio";
    printf("%s\n", mx_memset(c, 'q', 20));
    char v[] = "qwertyuio";
    memset(v, 'q', 4);
    printf("%s", v);
}*/
