#include "uls.h"

char **mx_read(int *current_flags, DIR *dptr, int *dir_count) {
    struct dirent  *ds;// = (struct dirent  *)malloc(sizeof(struct dirent) * 2000);
    char **F = (char **)malloc(sizeof(char *) * 2000);
    int j = 0;
    while((ds = readdir(dptr)) != 0) {//cчитываем хуйню из директории
        if(!current_flags[3] && !current_flags[4]) {// без потайных рифов, подло скрывающихся в волнах быстротечного потока
            if(ds->d_name[0] != '.') {
                F[j] = (char *)malloc(sizeof(char) * 256);
                F[j] = mx_strcpy(F[j],ds->d_name);
                j++;
            }
        } else if(current_flags[4]){//-a
            F[j] = ds->d_name;
            j++;
        } else {//-A
            if(ds->d_name[1] != '.' && ds->d_name[1] != '\0') {
                F[j] = ds->d_name;
                j++;
            }
        }
    }
    F[j] = NULL;
    *dir_count = j;
    free(ds);
    return F;
}
