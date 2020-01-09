#include "libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    void *help_v = 0;
    t_list *for_fun = lst; 
    int buf = 0;
    int i;
    int j;

    for(i = 0; i <= mx_list_size(lst); i++) {
        for(j = 0; j < mx_list_size(lst) - buf - 1 ; j++) {
            if(cmp(for_fun->data, for_fun->next->data) == false) {
                help_v = for_fun->data;
                for_fun->data = for_fun->next->data;
                for_fun->next->data = help_v;
            }
            for_fun = for_fun->next;
        }
        buf++;
        for_fun = lst;
    }
    return for_fun;
}

/*bool logic(void *first, void *second) {
    if(mx_strcmp((char*) first, (char *) second) < 0) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    bool (*cmp)(void *, void *) = NULL;
    cmp = &logic;
    t_list *part1 = mx_create_node("0");
    mx_push_back(&part1, "9");
    mx_push_back(&part1, "8");
    mx_push_back(&part1, "2");
    mx_push_back(&part1, "1");
    mx_push_back(&part1, "4");
    mx_push_back(&part1, "6");
    mx_printstr(part1->data);
    mx_printstr(part1->next->data);
    mx_printstr(part1->next->next->data);
    mx_printstr(part1->next->next->next->data);
    mx_printstr(part1->next->next->next->next->data);
    mx_printstr(part1->next->next->next->next->next->data);
    mx_printstr(part1->next->next->next->next->next->next->data);
    mx_sort_list(part1, cmp);
    mx_printstr("\n\n");
    mx_printstr(part1->data);
    mx_printstr(part1->next->data);
    mx_printstr(part1->next->next->data);
    mx_printstr(part1->next->next->next->data);
    mx_printstr(part1->next->next->next->next->data);
    mx_printstr(part1->next->next->next->next->next->data);
    mx_printstr(part1->next->next->next->next->next->next->data);
}*/
