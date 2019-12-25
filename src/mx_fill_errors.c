#include "uls.h"

int mx_fill_errors(int argc, char *argv[], int n_flags, char **E) {
    int n_errors = 0;

    for(int i = n_flags + 1; i < argc; i++) {
        struct stat buff;
        
        if(lstat(argv[i], &buff) == -1) {
            E[n_errors] = argv[i];
            n_errors++;
        } 
        E[n_errors] = NULL;         
    }
    return n_errors;
}
