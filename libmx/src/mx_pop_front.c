#include "libmx.h"

void mx_pop_front(t_list **head) {
    t_list *list = NULL;

    if (head == NULL || *head == NULL)
        return;
    list = (*head)->next;
    free(*head);
    *head = list;
}

/*t_list *mx_create_node(void *data);
void mx_push_back(t_list **list, void *data);
#include <stdio.h>
int main() {
    t_list *list = mx_create_node("xyz");
    mx_push_back(&list, "lol");
    printf("%s\n", (char*)list->data);
    printf("%s\n", (char*)list->next);
    mx_pop_front(&list);
    printf("%s\n", (char*)list->data);
    printf("%s\n", (char*)list->next);
}*/
