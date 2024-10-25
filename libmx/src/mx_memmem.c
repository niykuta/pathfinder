#include <../inc/libmx.h> 

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    if (big_len == 0 || little_len == 0 || big_len < little_len) {
        return NULL;
    }

    const unsigned char *cb = (const unsigned char *)big;
    const unsigned char *cl = (const unsigned char *)little;

    if (little_len == 1) {
        return memchr(big, *cl, big_len);
    }

    for (size_t i = 0; i <= big_len - little_len; i++) {
        if (cb[i] == cl[0] && memcmp(&cb[i], cl, little_len) == 0) {
            return (void *)(cb + i);
        }
    }

    return NULL;
}

