#include <../inc/libmx.h> 

void mx_push_back(t_list **list, void *data) {
    if (list == NULL) {
        return;
    }

    t_list *new_node = mx_create_node(data);

    if (new_node == NULL) {
        return;
    }

    t_list *current = *list;

    if (current == NULL) {
        *list = new_node;
        return;
    }

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}

