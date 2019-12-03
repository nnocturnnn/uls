#ifndef ULS_H
#define ULS_H

#include <stdio.h>
#include <wchar.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <malloc/malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/ioctl.h>
#include <sys/acl.h>
#include <sys/types.h> 
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <sys/acl.h>
#include <sys/xattr.h>
#include <time.h>
#include "libmx/inc/libmx.h"

typedef struct s_file {
    char *path;
    char *filename;
    char *size;
    char *size_h;
    char *owner; 
    char *short_time;
    char *full_time; 
    char *permissions; 
    char *links; 
    char *group;
    char *inode;  
    char *blksize;
    char *blocks;
    char acl_attr;
} t_file;

typedef struct all_s  {
    int n_errors;
    int n_files;
    int n_dirs;
} all_t;

int mx_atoi(const char *str);
bool mx_isspace(char c);
char *mx_strcat(char *restrict s1, const char *restrict s2);
int mx_strlen(const char *s);
char *mx_itoa(int number);
int mx_strcmp(const char *s1, const char *s2);
void mx_del_strarr(char ***arr);
void mx_printchar(char c);
char *mx_strcpy(char *dst, const char *src);
char *mx_strndup(const char *s1, size_t n);
char *mx_file_to_str(const char *file);
void mx_printerr(const char *s);
void mx_strdel(char **str);
char *mx_strnew(const int size);
int mx_get_char_index(const char *str, char c);
void mx_printint(int n);
char *mx_strdup(const char *s1);
char *mx_strndup(const char *s1, size_t n);
bool mx_isdigit(int c);
void mx_printstr(const char *s);
char *mx_strjoin(const char *s1, const char *s2);
bool mx_isalpha(int c);
int mx_count_flags(int argc, char *argv[], char *flags, int *current_flags);
int mx_fill_errors(int argc, char *argv[], int n_flags, char **E);
int mx_fill_files(int argc, char *argv[], int n_flags, char **F);
int mx_fill_dirs(int argc, char *argv[], int n_flags, char **D);
char *mx_get_permissions(struct stat file_stat);
char *mx_strncpy(char *dst, const char *src, int len);
char **mx_sort_arr(int len, char **arr);
void mx_cat_output(char **F, int *current_flags, char *Directory);
void mx_multicolumn_output(char **F,int n_files, int *current_flags, char *Directory);
void mx_long_output(char **F, int *current_flags, char* Directory);
char *mx_get_sort_time(struct stat buff, char *full_time, time_t current_time);
char *mx_get_group(struct stat buff, int *current_flags);
char *mx_get_owner(struct stat buff, int *current_flags);
t_file **mx_get_fileinfo(t_file **all, char **F, char *Directory, int *current_flags);
int mx_get_max_size(t_file **all);
int mx_get_max_links(t_file **all);
int mx_get_max_size_h(t_file **all);
int mx_get_max_owner(t_file **all);
int mx_get_max_group(t_file **all);
int mx_get_max_time(t_file **all);
int mx_get_max_size_h(t_file **all);
char *mx_get_full_time(/*struct stat buff,*/ char *full_time/*, time_t current_time*/);
char *mx_get_sizeh(char *size);
void mx_is_allowed(/*int *current_flags,*/ char *Directory);
char **mx_read(int *current_flags, DIR *dptr, int *dir_count);
void mx_R(int *current_flags, char **F, all_t all, char *Directory, int dir_count);
void mx_space(int count);
char mx_get_acl(char *filename);
void mx_get_total(char **F, char *Directory);
void mx_e_usage(int argc, char *argv[], int *n_flags,  char *flags, int *current_flags);
void mx_print_abcents(int n_errors, char **E);
void mx_print_files(int n_files, int n_dirs, char **F, int *current_flags);
void mx_print_dirs(all_t all, char **D, int *current_flags);
void mx_print_dname(int n_dirs, int n_files, int n_errors, char *dname);
char *mx_strchr(const char *s, int c);
int mx_get_char_index(const char *str, char c);
void mx_printname_f(char *F, int *current_flags);
void mx_link(int *current_flags, char *name1, t_file *all);
void mx_xattr(int *current_flags, t_file *all, t_file **all_f);
char **mx_strsplit(const char *s, char c);
int mx_count_words(const char *str, char c);
char *mx_sort_str(int len, char *str);
char *mx_sizetoa(size_t number);
size_t mx_atosize(const char *str);
char *mx_get_short_time(time_t time, char *full_time, time_t current_time);
void mx_acl(int *current_flags, t_file *all);
int *mx_get_current_flags(char *flags);
char **mx_quicksorty(char **arr, int left, int right);

#endif 
