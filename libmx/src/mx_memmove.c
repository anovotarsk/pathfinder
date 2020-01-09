#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    char *d = (char*) dst;
    char *s = (char*) src;
    char *tmp = (char*) malloc(len);
    size_t i;

    for (i = 0; i < len; i++) {
        tmp[i] = s[i];
    }
    for (i = 0; i < len; i++) {
        d[i] = tmp[i];
    }
    return dst;
}

/*#include <stdio.h>
#include <string.h>
int main() {
    char c[10];
    char s[] = "asdfghjkl;";
    printf("%s\n", s);
    printf("%s\n", mx_memmove(c, s, 5));
    printf("%s", memmove(c, s, 5));
}*/
