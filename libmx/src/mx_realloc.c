#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    void *new = NULL;
    char *s = NULL;
    char *p = NULL;
    size_t len;
    size_t i;

    if (ptr == NULL)
        return malloc(size);
    new = (void*) malloc(size);
    if (new == NULL || size == 0)
        return NULL;
    s = (char*) new;
    p = (char*) ptr;
    len = malloc_size(ptr);
    len = (size < len) ? size : len;
    for (i = 0; i < len; i++)
        *s++ = *p++;
    free(ptr);
    return new;
}

/*#include <stdio.h>
char *mx_strnew(const int size);

int main() {
    char *s = mx_strnew(10);
    for (int i = 0; i < 10; i++)
        s[i] = 'a';
    s[10] = '!';
    s = mx_realloc(s, 20);
    for (int i = 10; i < 20; i++)
        s[i] = 'q';
    s[19] = '\0';
    printf("%s", s);
}*/
