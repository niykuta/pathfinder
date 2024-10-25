#include <../inc/libmx.h> 

void *mx_memmove(void *dst, const void *src, size_t n) {
    if (dst == src || n == 0) {
        return dst; 
    }

    if (dst < src) {
        return mx_memcpy(dst, src, n);
    } 
    else {
        return mx_memrcpy(dst, src, n);
    }
}

