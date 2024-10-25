#include <../inc/libmx.h> 

char *mx_strjoin(const char *s1, const char *s2) {
    if (s1 == NULL && s2 == NULL) {
        return NULL;
    }

    if (s1 == NULL && s2 != NULL) {
        return mx_strdup(s2);
    }

    if (s2 == NULL && s1 != NULL) {
        return mx_strdup(s1);
    }

    int lenth = mx_strlen(s1) + mx_strlen(s2);
    char *str = mx_strnew(lenth);
    mx_strcpy(str, s1);
    mx_strcat(str, s2);
    
    return str;
}

