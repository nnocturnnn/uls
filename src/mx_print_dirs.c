#include "uls.h"

static void l_output(int dir_count, char **F, int *current_flags, char *Directory);
static void free_rub(DIR *dptr, char *Directory);
static void outputs(int dir_count, char **F, int *current_flags, char *Directory);

void mx_print_dirs(all_t all, char **D, int *current_flags) {
    int i = 0;
    while(D[i] != NULL) {
        mx_print_dname(all.n_dirs, all.n_files, all.n_errors, D[i]);
        DIR *dptr  = opendir(D[i]);
        if(dptr == NULL) {
            mx_is_allowed(/**/D[i]);//проверяем доступ
        } else {// если пермиссион разрешена
            int dir_count = 0;
            char **F = (char **)malloc(sizeof(char *) * 2000);
            F = mx_read(current_flags, dptr, &dir_count);//читаем директорию
            mx_quicksort(F, 0, dir_count - 1);//сортируем быстро и мощно
            outputs(dir_count, F, current_flags, D[i]);// вывод собсна
            mx_R(current_flags, F, all, D[i], dir_count);// -R
            free(F);
        } 
        i++;
        free_rub(dptr, D[i]);
    }
}

static void l_output(int dir_count, char **F, int *current_flags, char *Directory) {
    if(dir_count) {
        mx_get_total(F, Directory);
    }
    mx_long_output(F, current_flags, Directory);
}

static void free_rub(DIR *dptr, char *Directory) {
    if(dptr != NULL) {
        closedir(dptr);
    }
    if(Directory != NULL) {
        mx_printstr("\n");
    }
}

static void outputs(int dir_count, char **F, int *current_flags, char *Directory) {
    if(!current_flags[0] && !current_flags[10]) {//without -l / -o
        if(!isatty(1)) {// |cat -e
             mx_cat_output(F, current_flags, Directory);
        } else {// multicolumn output
            mx_multicolumn_output(F, dir_count, current_flags, Directory);
        }
    } else {// -l output
        l_output(dir_count, F, current_flags, Directory);
    }
}


