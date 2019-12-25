#include "uls.h"

int mx_fill_files(int argc, char *argv[], int n_flags, char **F) {
    int n_files = 0;

    for (int i = n_flags + 1; i < argc; i++) {
        struct stat buff;

        if (lstat(argv[i], &buff) != -1) {
            char *mode = mx_get_permissions(buff);

            if (mode[0] != 'd') {
                F[n_files] = argv[i];
                n_files++;
            }
        }
        F[n_files] = NULL;
    }
    return n_files;
}
