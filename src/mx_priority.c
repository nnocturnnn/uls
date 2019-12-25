#include "uls.h"

int *mx_priority(char *flags, char **argv, int n_flags) {
    int *prio_flag = malloc(sizeof(int) * mx_strlen(flags));
    int l = mx_strlen(flags);
    char *p = {"logn1Cm\0"};
    int arr[5];

    for (arr[0] = 0; arr[0] < l; arr[0]++) {
        prio_flag[arr[0]] = 0;
    }
    for (arr[1] = 1; arr[1] <= n_flags; arr[1]++)
        for (arr[2] = 1; arr[2] < mx_strlen(argv[arr[1]]); arr[2]++)
            for (arr[3] = 0; arr[3] < l; arr[3]++)
                if (argv[arr[1]][arr[2]] == flags[arr[3]] 
                    && mx_get_char_index(p, flags[arr[3]]) >= 0) {
                    for (arr[4] = 0; arr[4] < l; arr[4]++)
                        prio_flag[arr[4]] = 0;
                    prio_flag[arr[3]] = 1;
                }
    return prio_flag;
}
