NAME = uls

INC = ./inc/uls.h

HEADTMP = ./uls.h

SRC = ./main.c \
		./mx_acl.c \
		./mx_atosize.c \
		./mx_cat_output.c \
		./mx_count_words.c \
		./mx_countflags.c \
		./mx_fill_dirs.c \
		./mx_fill_errors.c \
		./mx_fill_files.c \
		./mx_get_acl.c \
		./mx_get_char_index.c \
		./mx_get_curent_flags.c \
		./mx_get_fileinfo.c \
		./mx_get_full_time.c \
		./mx_get_group.c \
		./mx_get_max_group.c \
		./mx_get_max_links.c \
		./mx_get_max_owner.c \
		./mx_get_max_size_h.c \
		./mx_get_max_size.c \
		./mx_get_max_time.c \
		./mx_get_owner.c \
		./mx_get_permissions.c \
		./mx_get_short_time.c \
		./mx_get_size_h.c \
		./mx_get_total.c \
		./mx_is_allowed.c \
		./mx_long_output.c \
		./mx_multicolumn_output.c \
		./mx_prin_dname.c \
		./mx_print_abcents.c \
		./mx_print_dirs.c \
		./mx_print_files.c \
		./mx_print_name_f.c \
		./mx_quicksorty.c \
		./mx_R.c \
		./mx_read.c \
		./mx_sizetoa.c \
		./mx_sort_str.c \
		./mx_space.c \
		./mx_xattr.c \

SRCS = ./src/main.c \
		./src/mx_acl.c \
		./src/mx_atosize.c \
		./src/mx_cat_output.c \
		./src/mx_count_words.c \
		./src/mx_countflags.c \
		./src/mx_fill_dirs.c \
		./src/mx_fill_errors.c \
		./src/mx_fill_files.c \
		./src/mx_get_acl.c \
		./src/mx_get_char_index.c \
		./src/mx_get_curent_flags.c \
		./src/mx_get_fileinfo.c \
		./src/mx_get_full_time.c \
		./src/mx_get_group.c \
		./src/mx_get_max_group.c \
		./src/mx_get_max_links.c \
		./src/mx_get_max_owner.c \
		./src/mx_get_max_size_h.c \
		./src/mx_get_max_size.c \
		./src/mx_get_max_time.c \
		./src/mx_get_owner.c \
		./src/mx_get_permissions.c \
		./src/mx_get_short_time.c \
		./src/mx_get_size_h.c \
		./src/mx_get_total.c \
		./src/mx_is_allowed.c \
		./src/mx_long_output.c \
		./src/mx_multicolumn_output.c \
		./src/mx_prin_dname.c \
		./src/mx_print_abcents.c \
		./src/mx_print_dirs.c \
		./src/mx_print_files.c \
		./src/mx_print_name_f.c \
		./src/mx_quicksorty.c \
		./src/mx_R.c \
		./src/mx_read.c \
		./src/mx_sizetoa.c \
		./src/mx_sort_str.c \
		./src/mx_space.c \
		./src/mx_xattr.c \

OBJ = ./main.o \
		./mx_acl.o \
		./mx_atosize.o \
		./mx_cat_output.o \
		./mx_count_words.o \
		./mx_countflags.o \
		./mx_fill_dirs.o \
		./mx_fill_errors.o \
		./mx_fill_files.o \
		./mx_get_acl.o \
		./mx_get_char_index.o \
		./mx_get_curent_flags.o \
		./mx_get_fileinfo.o \
		./mx_get_full_time.o \
		./mx_get_group.o \
		./mx_get_max_group.o \
		./mx_get_max_links.o \
		./mx_get_max_owner.o \
		./mx_get_max_size_h.o \
		./mx_get_max_size.o \
		./mx_get_max_time.o \
		./mx_get_owner.o \
		./mx_get_permissions.o \
		./mx_get_short_time.o \
		./mx_get_size_h.o \
		./mx_get_total.o \
		./mx_is_allowed.o \
		./mx_long_output.o \
		./mx_multicolumn_output.o \
		./mx_prin_dname.o \
		./mx_print_abcents.o \
		./mx_print_dirs.o \
		./mx_print_files.o \
		./mx_print_name_f.o \
		./mx_quicksorty.o \
		./mx_R.o \
		./mx_read.o \
		./mx_sizetoa.o \
		./mx_sort_str.o \
		./mx_space.o \
		./mx_xattr.o \

OBJO = ./obj/main.o \
		./obj/mx_acl.o \
		./obj/mx_atosize.o \
		./obj/mx_cat_output.o \
		./obj/mx_count_words.o \
		./obj/mx_countflags.o \
		./obj/mx_fill_dirs.o \
		./obj/mx_fill_errors.o \
		./obj/mx_fill_files.o \
		./obj/mx_get_acl.o \
		./obj/mx_get_char_index.o \
		./obj/mx_get_curent_flags.o \
		./obj/mx_get_fileinfo.o \
		./obj/mx_get_full_time.o \
		./obj/mx_get_group.o \
		./obj/mx_get_max_group.o \
		./obj/mx_get_max_links.o \
		./obj/mx_get_max_owner.o \
		./obj/mx_get_max_size_h.o \
		./obj/mx_get_max_size.o \
		./obj/mx_get_max_time.o \
		./obj/mx_get_owner.o \
		./obj/mx_get_permissions.o \
		./obj/mx_get_short_time.o \
		./obj/mx_get_size_h.o \
		./obj/mx_get_total.o \
		./obj/mx_is_allowed.o \
		./obj/mx_long_output.o \
		./obj/mx_multicolumn_output.o \
		./obj/mx_prin_dname.o \
		./obj/mx_print_abcents.o \
		./obj/mx_print_dirs.o \
		./obj/mx_print_files.o \
		./obj/mx_print_name_f.o \
		./obj/mx_quicksorty.o \
		./obj/mx_R.o \
		./obj/mx_read.o \
		./obj/mx_sizetoa.o \
		./obj/mx_sort_str.o \
		./obj/mx_space.o \
		./obj/mx_xattr.o \

CFLGS = -std=c11 -Wall -Wextra -Wpedantic -Werror# -g -fsanitize=address

all: install uninstall

install:
	@cd libmx && make -f Makefile install
	@cp $(INC) $(SRCS) .
	@clang $(CFLGS) -c  $(SRC)
	@mkdir  obj
	@mv $(OBJ) ./obj
	@clang $(CFLGS) $(OBJO) libmx/libmx.a -o $(NAME)

uninstall:
	@cd libmx && make -f Makefile uninstall
	@rm -rf $(OBJO) $(SRC) $(HEADTMP)
	@rm -rf ./obj

clean: uninstall
	@cd libmx && make -f Makefile clean
	@rm -rf $(NAME)

reinstall: clean all
