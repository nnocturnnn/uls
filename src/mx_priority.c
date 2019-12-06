#include "uls.h"

static int l_1_comb(char **argv, all_t all);
static int l_C_comb(char **argv, all_t all);
static int c_1_comb(char **argv, all_t all);
static int all_comb(char **argv, all_t all);

int mx_priority(int *cur_flag, char **argv, all_t all) {
	for(int i = 0; i < 18; i++) {
        if(cur_flag[0] && cur_flag[16] && cur_flag[17]) {
			return all_comb(argv, all);
		}
		else if(cur_flag[0] && cur_flag[16]) {
			return l_1_comb(argv, all);
		}
		else if(cur_flag[0] && cur_flag[17]) {
			return l_C_comb(argv, all);
		}
		else if(cur_flag[16] && cur_flag[17]) {
			return c_1_comb(argv, all);
		}
    }
    return -2;
}

static int l_1_comb(char **argv, all_t all) {
	int l = 0;
	int one = 0;

	for(int k = 1; k < all.n_flags + 1; k++) {
		l = k + mx_get_char_index_pr(argv[k], 'l');
		one = k + mx_get_char_index_pr(argv[k], '1');
	}
	if(l > one) {
		return 999999;	
	} else {
		return -1;
	}
}

static int l_C_comb(char **argv, all_t all) {
	int l = 0;
	int c = 0;

	for(int k = 1; k < all.n_flags + 1; k++) {
		l = k + mx_get_char_index_pr(argv[k], 'l');
		c = k + mx_get_char_index_pr(argv[k], 'C');
	}
	if(l > c) {
		return 999999;	
	} else {
		return 0;
	}
}

static int c_1_comb(char **argv, all_t all) {
	int one = 0;
	int c = 0;

	for(int k = 1; k < all.n_flags + 1; k++) {
		one = k + mx_get_char_index_pr(argv[k], '1');
		c = k + mx_get_char_index_pr(argv[k], 'C');
	}
	if(one > c) {
		return -1;	
	} else {
		return 0;
	}
}

static int all_comb(char **argv, all_t all) {
	int l = 0;
	int c = 0; 
	int one = 0;

	for(int k = 1; k <= all.n_flags; k++) {
		l = k + mx_get_char_index_pr(argv[k], 'l');
		one = k + mx_get_char_index_pr(argv[k], '1');
		c = k + mx_get_char_index_pr(argv[k], 'C');
	}
	if(l > one && l > c) {
		return 999999;
    }
	else if(c > one && c > l) {
		return 0;
	} 
    else {
		return -1;
	}
    return -3;
}




