#include "uls.h"

static all_t *init(int argc, char *argv[], t_arr arr);
static int r_n_flag(int argc, char **argv, int n_flags);
static int *r_cur_flag(int argc, char **argv, all_t all);
static t_arr *initarr(int argc);

int main(int argc, char *argv[]) {          
    t_arr *arr = initarr(argc);
    all_t *all = init(argc, argv, *arr);
    int *cur_flag = r_cur_flag(argc, argv, *all);
    
    sorty(*arr, *all, cur_flag);
   	mx_print_abcents(*all, arr->E);//ошибки
   	mx_print_files(*all, arr->F, cur_flag);//файлы
   	mx_print_dirs(*all, arr->D, cur_flag);//директории
    free(all);
    free(cur_flag);
}

static int r_n_flag(int argc, char **argv, int n_flags) {
                  //012345678901234567890
    char *flags = {"lRGAaTh@eLouingr1Cmp\0"};
    int *cur_flag = mx_get_current_flags(flags);

    n_flags = mx_count_flags(argc, argv, flags, cur_flag);
    free(cur_flag);
    return n_flags;
}

static int *r_cur_flag(int argc, char **argv, all_t all) {
    char *flags = {"lRGAaTh@eLouingr1Cmp\0"};
    int *cur_flag = mx_get_current_flags(flags);

    all.n_flags = mx_count_flags(argc, argv, flags, cur_flag);
    return cur_flag;
}

static all_t *init(int argc, char **argv, t_arr arr) {
    all_t *data = malloc(sizeof(all_t));
    int n_flags = 1;
    char *flags = {"lRGAaTh@eLouingr1Cmp\0"};
    int *cur_flag = mx_get_current_flags(flags);

    n_flags = mx_count_flags(argc, argv, flags, cur_flag);
    n_flags = r_n_flag(argc, argv, n_flags);
    data->n_flags = n_flags;
    data->n_errors =  mx_fill_errors(argc, argv, n_flags, arr.E);
    data->n_files = mx_fill_files(argc, argv, n_flags, arr.F);
    data->n_dirs = mx_fill_dirs(argc, argv, n_flags, arr.D);
    data->priority = mx_priority(flags, argv, n_flags);
    return data;
}

static t_arr *initarr(int argc) {
    t_arr *data = malloc(sizeof(t_arr));
    char **F = (char **)malloc(sizeof(char *) * argc);//масив файлов
   	char **D = (char **)malloc(sizeof(char *) * 100);//масив директорий
   	char **E = (char **)malloc(sizeof(char *) * argc);//масив ошибок

    data->F = F;
    data->D = D;
    data->E = E;
    return data;
}
