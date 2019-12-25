#include "uls.h"

void mx_checksort(char **F, int *cur_flag, int dir_count) {
    if (cur_flag[15]) //-r
        mx_backsorty(F, 0, dir_count - 1);
    else
        mx_quicksort(F, 0, dir_count - 1);
}
