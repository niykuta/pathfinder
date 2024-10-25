#include <../inc/libmx.h> 
 
int mx_binary_search(char **arr, int size, const char *s, int *count) { 
    int first = 0; 
    int last = size - 1; 
    *count = 0;
    
    while (first <= last) { 
        (*count)++; 
        
        int middle = (first + last) / 2; 
        int cmp = mx_strcmp(arr[middle], s); 
 
        if (cmp == 0) { 
            return middle; 
        } 
        else if (cmp < 0) { 
            first = middle + 1; 
        } 
        else { 
            last = middle - 1; 
        } 
    } 
 
    *count = 0; 
    return -1; 
}

