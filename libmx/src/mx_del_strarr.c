#include "libmx.h"

void mx_del_strarr(char ***arr) {
    char **box = *arr;

    while(*box != NULL) {
        mx_strdel(box);
        box++;
    }
    mx_strdel(box);
    free(*arr);
    *arr = NULL; 
}

/*int main() {
    char **arr = (char**) malloc(4);
    arr[0] = mx_strnew(10);
    arr[1] = mx_strnew(10);
    arr[2] = mx_strnew(10);
    //arr[0][0] = 'Q';
    for (int a = 0; a < 3; a++) {
        for (int i = 0; i < 4; i++)
            arr[a][i] = 'Q';
    }
    arr[3] = NULL;
    mx_del_strarr(&arr);
    if (arr == NULL) 
        mx_printstr("NULL");
    return 0;
}*/
