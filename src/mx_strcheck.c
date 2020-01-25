#include "../inc/pathfinder.h"

int mx_atoi(char *str) {
    int len = mx_strlen(str);
    int num = 0;
    int i;

    for (i = 0; i < len; i++) {
        if (str[i] >= 48 && str[i] <= 57) {
            num += str[i] - 48;
            num *= 10;
        }
        else
            return -1;
    }
    return num / 10;
}

bool mx_isalphabetic(char *str) {
    int i;
    int len = mx_strlen(str);

    for (i = 0; i < len; i++) {
        if ((str[i] >= 65 && str[i] <= 90) != true) {
            if ((str[i] >= 97 && str[i] <= 122) != true) {
                return false;
            }
        }
    }
    return true;
}

char *mx_strcat_del(char *s1, char *s2, char *del) {
    char *tmp1;
    char *tmp2;

    if (mx_strcmp(s1, "") == 0) {
        mx_strdel(&s1);
        tmp1 = mx_strdup(s2);
        mx_strdel(&s2);
        return tmp1;
    }
    tmp1 = mx_strcat(s1, del);
    mx_strdel(&s1);
    tmp2 = mx_strcat(tmp1, s2);
    mx_strdel(&s2);
    mx_strdel(&tmp1);
    return tmp2;
}
