#include <../inc/libmx.h> 

char *mx_strndup(const char *s1, size_t n) {
    size_t len = mx_strlen(s1);
    char *dup = mx_strnew(n);

    if(n > len) {
        n = len;
    }

    if (dup == NULL) {
        return NULL;
    }

    return mx_strncpy(dup, s1, n);
}


