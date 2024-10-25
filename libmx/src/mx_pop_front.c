#include <../inc/libmx.h> 

void mx_pop_front(t_list **head) {
    if (head == NULL) {
        return;
    }

    t_list *current = *head;

    if (current == NULL) {
        return;
    }

    *head = current->next;
    free(current);
}

