#include <../inc/libmx.h> 

void *mx_memrchr(const void *s, int c, size_t n) {
    const unsigned char *src = (const unsigned char *)s;
    unsigned char ch = (unsigned char)c;

    for (size_t i = n - 1; i < n; i--) {
        if (src[i] == ch) {
            return (void *)((char *)src + i);
        }
    }
    
    return NULL;
}

