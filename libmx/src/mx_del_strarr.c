#include <../inc/libmx.h> 

void mx_del_strarr(char ***str) {
    if (*str == NULL || str == NULL) {
        return;
    }

    for (int i = 0; (*str)[i] != NULL; i++) {
        mx_strdel(&((*str)[i]));
    }
    
    free(*str);
    *str = NULL;
}

