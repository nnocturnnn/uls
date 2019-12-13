#include "uls.h"

static char *get_path(char *File, char *Directory);

void mx_R(int *cur_flag, char **F, all_t all, char *Directory, int dir_count) {
    if(cur_flag[1] == 1) {//-R
        for (int i = 0; i < dir_count; i++) {
        	char *path = get_path(F[i], Directory);
        	struct stat buff;
        	lstat(path, &buff);
        	char *mode = mx_get_permissions(buff);
            if(mode[0] == 'd' && (mx_strcmp(F[i], ".") != 0 && mx_strcmp(F[i], "..") != 0)) {    
                char **rec_D = malloc(sizeof(char *) * 200);
                mx_printstr("\n");
                mx_printstr(path);
                mx_printstr(":");
                mx_printstr("\n");
                rec_D[0] = path;
                rec_D[1] = NULL; 
                mx_print_dirs(all, rec_D, cur_flag);
                free(rec_D);
            }
        }
    }
}

static char *get_path(char *File, char *Directory) {
    char *path = malloc(sizeof(char *));
    path = mx_strjoin(path,Directory);
    path = mx_strjoin(path,"/");
    path = mx_strjoin(path,File);
    return path;
}
