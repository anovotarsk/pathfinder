#include "libmx.h"

void mx_push_front(t_list **list, void *data) {
    t_list *node = mx_create_node(data);

    node->next = *list;
    *list = node;
}

/*#include <stdio.h>
int main() {
    t_list *list = mx_create_node("xyz");
    printf("%s\n", (char*)list->data);
    printf("%s\n", (char*)list->next);
    mx_push_front(&list, "lol");
    printf("%s\n", (char*)list->data);
    printf("%s\n", (char*)list->next);
}*/
