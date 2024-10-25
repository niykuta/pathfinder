#include <../inc/libmx.h> 

void mx_print_unicode(wchar_t c) {    
    char byte[4];
    int size;

    if (c < 0x80) {        
        byte[0] = c;
        size = 1;    
    }
    else if (c < 0x0800) {        
        byte[0] = (0xC0 | (c >> 6));
        byte[1] = (0x80 | (c & 0x3F));        
        size = 2;
    }    
    else if (c < 0x010000) {
        byte[0] = (0xE0 | (c >> 12));        
        byte[1] = (0x80 | ((c >> 6) & 0x3F));
        byte[2] = (0x80 | (c & 0x3F));       
        size = 3;
    }    
    else {
        byte[0] = (0xF0 | (c >> 18));        
        byte[1] = (0x80 | ((c >> 12) & 0x3F));
        byte[2] = (0x80 | ((c >> 6) & 0x3F));        
        byte[3] = (0x80 | (c & 0x3F));
        size = 4;    
    }

    write(1, &byte, size);
}

