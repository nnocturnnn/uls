#include "uls.h"

int mx_count_words(const char *str, char c) {
    int res = 0;
    if(str == NULL){
        res--;
        return res;
    }
    int word = 0;
    for ( ; *str; ++str) {
        if (*str != c) {
            if (word == 0) {
                word =1;
                res++;
            }
        }
        else if (word) {
            word = 0;
        }
    }
    return res;
}
