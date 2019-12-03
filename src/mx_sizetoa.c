#include "uls.h"

static int mx_numlen(size_t num);

static int mx_numlen(size_t num) {
    int len = 0;

    while (num > 0) {
        num /= 10;
        len++;
    }
    return len == 0 ? 1 : len;
}

char *mx_sizetoa(size_t number) {
    int len = mx_numlen(number);
    char *result = mx_strnew(len);
    int min = 0;

    for (int i = len - 1; i >= min; i--) {
        result[i] = (number % 10) + '0';
        number /= 10;
    }
    return result;
}
