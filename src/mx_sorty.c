#include "uls.h"

void mx_sorty(t_arr arr, t_all all, int *cur_flag) {
  if(all.n_dirs) {
    mx_checksort(arr.D, cur_flag, all.n_dirs);
  }
  if(all.n_files) {
    mx_checksort(arr.F, cur_flag, all.n_files);
  }
  if(all.n_errors) {
    mx_checksort(arr.E, cur_flag, all.n_errors);
  }
}
