#include "uls.h"

void mx_quicksorty(char **D, char **F, char **E, all_t all) {
    if(all.n_dirs) {
        mx_quicksort(D, 0, all.n_dirs - 1);
    }
    if(all.n_files) {
        mx_quicksort(F, 0, all.n_files - 1);
    }
    if(all.n_errors) {
        mx_quicksort(E, 0, all.n_errors - 1);
    }
}
