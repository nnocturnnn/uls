#include "uls.h"

static all_t *init(int argc, char *argv[], char **F, char **E, char **D);
static void sorty(char **D, char **F, char **E, all_t all);
static int r_n_flag(int argc, char **argv, int n_flags);
static int *r_cur_flag(int argc, char **argv, all_t all);

int main(int argc, char *argv[]) {
    char **F = (char **)malloc(sizeof(char *) * argc);//масив файлов
   	char **D = (char **)malloc(sizeof(char *) * 100);//масив директорий
   	char **E = (char **)malloc(sizeof(char *) * argc);//масив ошибок
    all_t *all = init(argc, argv, F, E, D);
    int *cur_flag = r_cur_flag(argc, argv, *all);
    mx_priority(cur_flag, argv, *all));
    
    sorty(D, F, E, *all);
   	mx_print_abcents(*all, E);//ошибки
   	mx_print_files(*all, F, cur_flag);//файлы
   	mx_print_dirs(*all, D, cur_flag);//директории
    free(all);
    free(cur_flag);
}

static int r_n_flag(int argc, char **argv, int n_flags) {
    char *flags = {"lRGAaTh@eLouingr1C\0"};
    int *cur_flag = mx_get_current_flags(flags);

    n_flags = mx_count_flags(argc, argv, flags, cur_flag);
    free(cur_flag);
    return n_flags;
}

static int *r_cur_flag(int argc, char **argv, all_t all) {
    char *flags = {"lRGAaTh@eLouingr1C\0"};
    int *cur_flag = mx_get_current_flags(flags);

    all.n_flags = mx_count_flags(argc, argv, flags, cur_flag);
    return cur_flag;
}

static void sorty(char **D, char **F, char **E, all_t all) {
  if(all.n_dirs) {
    mx_quicksort(D, 0, all.n_dirs - 1);
  }
  if(all.n_files) {
    mx_quicksort(F, 0, all.n_files - 1);
  }
  if(all.n_errors) {
    mx_quicksort(E, 0, all.n_errors - 1);
  }
}

static all_t *init(int argc, char **argv, char **F, char **E, char **D) {
    all_t *data= malloc(sizeof(all_t));
    int n_files = 0;//количество файлов
   	int n_dirs = 0;//количество директорий
   	int n_errors = 0;//количество ошибок
    int n_flags = 1;

    n_flags = r_n_flag(argc, argv, n_flags);
    n_errors = mx_fill_errors(argc, argv, n_flags, E);
    n_files = mx_fill_files(argc, argv, n_flags, F);
    n_dirs = mx_fill_dirs(argc, argv, n_flags, D);
    data->n_flags = n_flags;
    data->n_errors =  n_errors;
    data->n_files = n_files;
    data->n_dirs = n_dirs;
    return data;
}
