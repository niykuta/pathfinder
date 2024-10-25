#include <../inc/libmx.h> 

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    unsigned char *d = (unsigned char *)dst;
    const unsigned char *s = (const unsigned char *)src;

    for (size_t i = 0; i < n; i++) {
        d[i] = s[i];
        if (d[i] == (unsigned char)c) {
            return d + i + 1;
        }
    }

    return NULL;
}

