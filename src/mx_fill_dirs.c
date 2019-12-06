#include "uls.h"

int mx_fill_dirs(int argc, char *argv[], int n_flags, char **D) {
    int n_dirs = 0;
    if(argc == n_flags + 1) {
        D[0] = ".";
        D[1] = NULL;
        return 0;
    }
    for(int i = n_flags + 1; i < argc; i++) {
        struct stat buff;
        if(lstat(argv[i], &buff) != -1) {
            char *mode = mx_get_permissions(buff);
            if (mode[0] == 'd') { 
                D[n_dirs] = argv[i];
                n_dirs++;   
            }
        } 
        D[n_dirs] = NULL;         
    }
    return n_dirs;
}
