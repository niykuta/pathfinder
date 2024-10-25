#include "../inc/libmx.h"

char *mx_itoa(int number) {    
    int length = (number <= 0) ? 1 : 0;

    for (int temp = number; temp != 0; temp /= 10) {        
        length++;
    }

    char *result = mx_strnew(length);

    if (!result) {        
        return NULL;
    }    

    if (number == 0) {        
        result[0] = '0';
        return result;    
    }

    unsigned int num = (number < 0) ? -number : number;
    result[length--] = '\0';
    
    while (num > 0) {        
        result[length--] = (num % 10) + '0';
        num /= 10;    
    }
    
    if (number < 0) {
        result[0] = '-';    
    }
    
    return result;
}

