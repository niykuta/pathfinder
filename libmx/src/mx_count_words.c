#include <../inc/libmx.h> 

int mx_count_words(const char *str, char c) {  
    if (str == NULL) {
        return -1;
    }

    int count = 0;  
    int in_word = 0;  
  
    while (*str != '\0') {  
        if (*str == c) {  
            in_word = 0;  
        } 
        else if (in_word == 0) {  
            in_word = 1;  
            count++;  
        }  
        
        str++;  
    }  

    return count;  
}

