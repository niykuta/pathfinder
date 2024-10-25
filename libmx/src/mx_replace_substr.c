#include <../inc/libmx.h> 

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (!str || !sub || !replace) {
        return NULL;
    }

    int str_len = mx_strlen(str);
    int sub_len = mx_strlen(sub);
    int replace_len = mx_strlen(replace);

    if (str_len == 0 || sub_len == 0) {
        return mx_strdup(str);
    }

    int res_len = str_len + mx_count_substr(str, sub) * (replace_len - sub_len);
    char *res = mx_strnew(res_len);

    if (!res) {
        return NULL;
    }

    const char *ptr = str;  
    char *res_ptr = res;    

    while (*ptr) {
        if (mx_strncmp(ptr, sub, sub_len) == 0) {  
            mx_strcpy(res_ptr, replace);  
            res_ptr += replace_len;       
            ptr += sub_len;            
        } 
        else {
            *res_ptr = *ptr;  
            res_ptr++;
            ptr++;
        }
    }

    *res_ptr = '\0';  
    return res;
}

