#include <../inc/libmx.h> 

void mx_printint(int n) {
    long num = n;

    if (num < 0) {
        mx_printchar('-');
        num *= -1;
    }

    int n_next = num / 10;

    if (n_next != 0) {
        mx_printint(n_next);
    }

    mx_printchar((num % 10) + 48);
}

