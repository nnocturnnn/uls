#include "uls.h"

static all_t *inicialize(int n_errors, int n_files, int n_dirs);
static void sorty(char **D, char **F, char **E, all_t all);

int main(int argc, char *argv[]) {
    char **F = (char **)malloc(sizeof(char *) * argc);//масив файлов
   	char **D = (char **)malloc(sizeof(char *) * 100);//масив директорий
   	char **E = (char **)malloc(sizeof(char *) * argc);//масив ошибок
   	int n_files = 0;//количество файлов
   	int n_dirs = 0;//количество директорий
   	int n_errors = 0;//количество ошибок
   	int n_flags = 1;//количество флагов
   	char *flags = {"lRGAaTh@eLouin\0"};
   	int *current_flags = mx_get_current_flags(flags);

   	n_flags = mx_count_flags(argc, argv, flags, current_flags);//ну и считываем текущие флаги кншн
    n_errors = mx_fill_errors(argc, argv, n_flags, E);
    n_files = mx_fill_files(argc, argv, n_flags, F);
    n_dirs = mx_fill_dirs(argc, argv, n_flags, D);
    all_t *all = inicialize(n_errors, n_files, n_dirs);
    sorty(D, F, E, *all);
   	mx_print_abcents(n_errors, E);//ошибки
   	mx_print_files(n_files, n_dirs, F, current_flags);//файлы
   	mx_print_dirs(*all, D, current_flags);//директории
    free(all);
    free(current_flags);
}

static all_t *inicialize(int n_errors, int n_files, int n_dirs) {
    all_t *data= malloc(sizeof(all_t));
    data->n_errors = n_errors;
    data->n_files = n_files;
    data->n_dirs = n_dirs;
    return data;
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
