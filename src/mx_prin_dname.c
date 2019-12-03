#include "uls.h"

void mx_print_dname(int n_dirs, int n_files, int n_errors, char *dname) {
   if(n_dirs > 1 || n_files || n_errors) {
        mx_printstr(dname);
        mx_printstr(":");
        mx_printstr("\n");
    }
}

