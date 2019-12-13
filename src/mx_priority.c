#include "uls.h"

int *mx_priority(char *flags, char **argv, int n_flags) {
    int *prio_flag = malloc(sizeof(int) * mx_strlen(flags));
    int l = mx_strlen(flags);
    char *p = {"logn1Cm\0"};

    for (int q = 0; q < l; q++) {
        prio_flag[q] = 0;
    }
    for(int i = 1; i <= n_flags; i++) {
        for(int j = 1; j < mx_strlen(argv[i]); j++) {
            for (int k = 0; k < l; k++) {
                if(argv[i][j] == flags[k] 
                   && mx_get_char_index(p, flags[k]) >= 0) {
                    for(int c = 0; c < l; c++) {
                        prio_flag[c] = 0;
                    }
                    prio_flag[k] = 1;
                }
            }
        }
    } return prio_flag;
}
