#include <../inc/libmx.h> 

char *mx_strstr(const char *haystack, const char *needle) {
    if (!*needle) {
        return (char*)haystack;
    }

    int needle_len = mx_strlen(needle);

    while (*haystack) {
        char *substring_start = mx_strchr(haystack, *needle);

        if (substring_start != NULL && mx_strncmp(substring_start, needle, needle_len) == 0) {
            return substring_start; 
        }
        
        haystack++;
    }

    return NULL; 
}

