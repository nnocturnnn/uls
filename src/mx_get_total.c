#include "uls.h"

void mx_get_total(char **F, char *Directory) {
    int i = 0; 
    int total = 0;
    while(F[i] != NULL) {
        char *path = malloc(sizeof(char *));
        path = mx_strjoin(path,Directory);
        path = mx_strjoin(path,"/");
        path = mx_strjoin(path,F[i]);
        struct stat buff;
        lstat(path, &buff);
        total += buff.st_blocks;
        i++;
    }
    mx_printstr("total ");
    mx_printstr(mx_itoa(total));
    mx_printstr("\n");
}
