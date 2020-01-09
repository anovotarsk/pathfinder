#include "../inc/pathfinder.h"

int mx_atoi(char *str) {
    int len = mx_strlen(str);
    unsigned long int num = 0;
    int i;

    for (i = 0; i < len; i++) {
        if (str[i] >= 47 && str[i] <= 57) {
            num += str[i] - 48;
            num *= 10;
        }
        else
            return -1;
    }
    if (num > 2147483647)
        return -1;
    return num / 10;
}
