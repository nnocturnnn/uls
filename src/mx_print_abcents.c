#include "uls.h"

void mx_print_abcents(t_all all, char **E) {
    int i = 0;

    if (all.n_errors) 
        while (E[i] != NULL) {
            DIR *dptr = opendir(E[i]);

            if (dptr == NULL) {
                char *str = mx_strnew(1);

                str = mx_strjoin(str, "uls: ");
                str = mx_strjoin(str, E[i]);
                perror(str);
            }
            i++;
        }
}
