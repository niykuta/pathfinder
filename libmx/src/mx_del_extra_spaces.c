#include <../inc/libmx.h> 

char *mx_del_extra_spaces(const char *str) {
    if (str == NULL) {
        return NULL;
    }

    int len = mx_strlen(str);
    char* new = mx_strnew(len);
    int j = 0;
    bool word = false;

    for (int i = 0; i < len; i++) {
        if (!mx_isspace(str[i])) {
            new[j] = str[i];
            j++;
            word = true;
        }
        else if (word) {
            new[j] = ' ';
            j++;
            word = false;
        }
    }

    new[j] = '\0';
    return mx_strtrim(new);
}



