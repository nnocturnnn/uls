#include "uls.h"

bool mx_isspace(char c);
bool mx_isdigit(int c);

size_t mx_atosize(const char *str) {
    int i = 0;
    size_t res = 0;
    while (mx_isspace(str[i])){
        i++;
    }
    while (str[i] && mx_isdigit(str[i])) {
        res = res * 10 + str[i] - 48;
        i++;
    }
    return res;
}
