#include "uls.h"

static void l_output(int dir_count, char **F, int *cur_flag, char *Directory);
static void free_rub(DIR *dptr, char *Directory);
static void outputs(int dir_count, char **F, int *cur_flag, char *Directory);
static void checksort(char **D, int *cur_flag, int dir_count);

void mx_print_dirs(all_t all, char **D, int *cur_flag) {
    int i = 0;
    while(D[i] != NULL) {
        mx_print_dname(all.n_dirs, all.n_files, all.n_errors, D[i]);
        DIR *dptr  = opendir(D[i]);
        if(dptr == NULL) {
            mx_is_allowed(/**/D[i]);//проверяем доступ
        } else {// если пермиссион разрешена
            int dir_count = 0;
            char **F = (char **)malloc(sizeof(char *) * 2000);
            F = mx_read(cur_flag, dptr, &dir_count);//читаем директорию
            checksort(F, cur_flag, dir_count);
            outputs(dir_count, F, cur_flag, D[i]);// вывод собсна
            mx_R(cur_flag, F, all, D[i], dir_count);// -R
            free(F);
        } 
        i++;
        free_rub(dptr, D[i]);
    }
}

static void l_output(int dir_count, char **F, int *cur_flag, char *Directory) {
    if(dir_count) {
        mx_get_total(F, Directory);
    }
    mx_long_output(F, cur_flag, Directory);
}

static void free_rub(DIR *dptr, char *Directory) {
    if(dptr != NULL) {
        closedir(dptr);
    }
    if(Directory != NULL) {
        mx_printstr("\n");
    }
}

static void outputs(int dir_count, char **F, int *cur_flag, char *Directory) {
    if(!cur_flag[0] && !cur_flag[10] && !cur_flag[14]) {//without -l / -o
        if(!isatty(1)) {// |cat -e
            mx_cat_output(F, cur_flag, Directory);
        } else {// multicolumn output
            mx_multicolumn_output(F, dir_count, cur_flag, Directory);
        }
    } else {// -l output
        l_output(dir_count, F, cur_flag, Directory);
    }
}

static void checksort(char **F, int *cur_flag, int dir_count) {
    if(cur_flag[15]) {
        mx_backsort(F, 0, dir_count - 1);
    } else {
        mx_quicksort(F, 0, dir_count - 1);
    }
}
