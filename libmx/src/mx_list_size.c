#include "libmx.h"

int mx_list_size(t_list *list) {
    int len = 0;

    while (list != NULL) {
        list = list->next;
        len++;
    }
    return len;
}

/*t_list *mx_create_node(void *data);
void mx_push_back(t_list **list, void *data);
#include <stdio.h>
int main() {
    t_list *list = mx_create_node("xyz");
    mx_push_back(&list, "lol");
    mx_push_back(&list, "blzt");
    printf("%d\n", mx_list_size(list));
}*/
