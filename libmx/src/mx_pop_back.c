#include <../inc/libmx.h> 

void mx_pop_back(t_list **head) {
    if (head == NULL) {
        return;
    }

    t_list *current = *head;

    if (current == NULL || current->next == NULL) {
        free(current);
        *head = NULL;
        return;
    }

    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

