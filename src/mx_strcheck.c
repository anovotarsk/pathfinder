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
        if ((str[i] >= 65 && str[i] <= 90)
             || ((str[i] >= 97 && str[i] <= 122)))
            return true;
        return false;
    }
    return false;
}
