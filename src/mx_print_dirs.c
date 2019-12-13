#include "uls.h"

static void l_output(int dir_c, char **F, int *cur_flag, char *D);
static void free_rub(DIR *dptr, char *D);
static void outputs(int dir_c, char **F, int *cur_flag, char *D, int *prior);

void mx_print_dirs(all_t all, char **D, int *cur_flag) {
    int i = 0;
    while(D[i] != NULL) {
        mx_print_dname(all.n_dirs, all.n_files, all.n_errors, D[i]);
        DIR *dptr  = opendir(D[i]);
        if(dptr == NULL) {
            mx_is_allowed(D[i]);//проверяем доступ
        } else {// если пермиссион разрешена
            int dir_c = 0;
            char **F = (char **)malloc(sizeof(char *) * 2000);
            F = mx_read(cur_flag, dptr, &dir_c);//читаем директорию
            mx_checksort(F, cur_flag, dir_c);
            outputs(dir_c, F, cur_flag, D[i], all.priority);// вывод собсна
            mx_R(cur_flag, F, all, D[i], dir_c);// -R
            free(F);
        } 
        i++;
        free_rub(dptr, D[i]);
    }
}

static void l_output(int dir_c, char **F, int *cur_flag, char *D) {
    if(dir_c) {
        mx_get_total(F, D);
    }
    mx_long_output(F, cur_flag, D);
}

static void free_rub(DIR *dptr, char *D) {
    if(dptr != NULL) {
        closedir(dptr);
    }
    if(D != NULL) {
        mx_printstr("\n");
    }
}

static void outputs(int dir_c, char **F, int *cur_flag, char *D, int *prior) {
    if(!prior[0] && !prior[10] && !prior[13] && !prior[14] ) {
        if(!isatty(1)) {// |cat -e
            mx_cat_output(F, cur_flag, D);
        } else if (cur_flag[16] && prior[16]){
            mx_1_output(F, cur_flag, D);
        } else if (cur_flag[18] && prior[18]) {
            mx_m_output(F, cur_flag, D);
        }  else {// multicolumn output
            mx_multicolumn_output(F, dir_c, cur_flag, D);
        }
    } else {// -l output
        l_output(dir_c, F, cur_flag, D);
    }
}


