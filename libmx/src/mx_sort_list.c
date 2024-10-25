#include <../inc/libmx.h> 

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {    
    if (lst == NULL || cmp == NULL) {
        return NULL;    
    }

    t_list *start = lst;
    t_list *end = NULL;    
    t_list *current;
    t_list *next;

    while (end != start->next) {        
        current = start;

        while (current->next != end) {
            next = current->next;

            if (cmp(current->data, next->data)) {        
                void *temp = current->data;
                current->data = next->data;                
                next->data = temp;
            }

            current = current->next;        
        }

        end = current;
    }

    return start;
}

