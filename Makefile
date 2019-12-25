NAME = uls

INC = ./inc/uls.h

HEADTMP = ./uls.h

SRC = ./main.c \
	./mx_get_current_flags.c \
	./mx_count_flags.c \
	./mx_fill_errors.c \
	./mx_fill_files.c \
	./mx_get_permissions.c \
	./mx_fill_dirs.c \
	./mx_priority.c \
	./mx_sorty.c \
	./mx_checksort.c \
	./mx_backsorty.c \
	./mx_sort_str.c \
	./mx_print_abcents.c \
	./mx_print_files.c \
	./mx_cat_output.c \
	./mx_get_fileinfo.c \
	./mx_get_acl.c \
	./mx_get_owner.c \
	./mx_get_group.c \
	./mx_get_size.c \
	./mx_get_size_h.c \
	./mx_get_full_time.c \
	./mx_get_short_time.c \
	./mx_1_output.c \
	./mx_m_output.c \
	./mx_printname_f.c \
	./mx_multicolumn_output.c \
	./mx_long_output.c \
	./mx_flong_out.c \
	./mx_slong_out.c \
	./mx_xattr.c \
	./mx_acl.c \
	./mx_get_controls.c \
	./mx_space.c \
	./mx_sizetoa.c \
	./mx_get_max_size.c \
	./mx_print_user.c \
	./mx_print_permissions.c \
	./mx_print_controls.c \
	./mx_get_max_group.c \
	./mx_get_max_owner.c \
	./mx_get_max_links.c \
	./mx_print_inode.c \
	./mx_get_short_size.c \
	./mx_def_space.c \
	./mx_get_max_time.c \
	./mx_print_dirs.c \
	./mx_print_dname.c \
	./mx_is_allowed.c \
	./mx_R.c \
	./mx_get_total.c \
	./mx_read.c \

SRCS = ./src/main.c \
	./src/mx_get_current_flags.c \
	./src/mx_count_flags.c \
	./src/mx_fill_errors.c \
	./src/mx_fill_files.c \
	./src/mx_get_permissions.c \
	./src/mx_fill_dirs.c \
	./src/mx_priority.c \
	./src/mx_sorty.c \
	./src/mx_checksort.c \
	./src/mx_backsorty.c \
	./src/mx_sort_str.c \
	./src/mx_print_abcents.c \
	./src/mx_print_files.c \
	./src/mx_cat_output.c \
	./src/mx_get_fileinfo.c \
	./src/mx_get_acl.c \
	./src/mx_get_owner.c \
	./src/mx_get_group.c \
	./src/mx_get_size.c \
	./src/mx_get_size_h.c \
	./src/mx_get_full_time.c \
	./src/mx_get_short_time.c \
	./src/mx_1_output.c \
	./src/mx_m_output.c \
	./src/mx_printname_f.c \
	./src/mx_multicolumn_output.c \
	./src/mx_long_output.c \
	./src/mx_flong_out.c \
	./src/mx_slong_out.c \
	./src/mx_xattr.c \
	./src/mx_acl.c \
	./src/mx_get_controls.c \
	./src/mx_space.c \
	./src/mx_sizetoa.c \
	./src/mx_get_max_size.c \
	./src/mx_print_user.c \
	./src/mx_print_permissions.c \
	./src/mx_print_controls.c \
	./src/mx_get_max_group.c \
	./src/mx_get_max_owner.c \
	./src/mx_get_max_links.c \
	./src/mx_print_inode.c \
	./src/mx_get_short_size.c \
	./src/mx_def_space.c \
	./src/mx_get_max_time.c \
	./src/mx_print_dirs.c \
	./src/mx_print_dname.c \
	./src/mx_is_allowed.c \
	./src/mx_R.c \
	./src/mx_get_total.c \
	./src/mx_read.c \
		

OBJ = ./main.o \
	./mx_get_current_flags.o \
	./mx_count_flags.o \
	./mx_fill_errors.o \
	./mx_fill_files.o \
	./mx_get_permissions.o \
	./mx_fill_dirs.o \
	./mx_priority.o \
	./mx_sorty.o \
	./mx_checksort.o \
	./mx_backsorty.o \
	./mx_sort_str.o \
	./mx_print_abcents.o \
	./mx_print_files.o \
	./mx_cat_output.o \
	./mx_get_fileinfo.o \
	./mx_get_acl.o \
	./mx_get_owner.o \
	./mx_get_group.o \
	./mx_get_size.o \
	./mx_get_size_h.o \
	./mx_get_full_time.o \
	./mx_get_short_time.o \
	./mx_1_output.o \
	./mx_m_output.o \
	./mx_printname_f.o \
	./mx_multicolumn_output.o \
	./mx_long_output.o \
	./mx_flong_out.o \
	./mx_slong_out.o \
	./mx_xattr.o \
	./mx_acl.o \
	./mx_get_controls.o \
	./mx_space.o \
	./mx_sizetoa.o \
	./mx_get_max_size.o \
	./mx_print_user.o \
	./mx_print_permissions.o \
	./mx_print_controls.o \
	./mx_get_max_group.o \
	./mx_get_max_owner.o \
	./mx_get_max_links.o \
	./mx_print_inode.o \
	./mx_get_short_size.o \
	./mx_def_space.o \
	./mx_get_max_time.o \
	./mx_print_dirs.o \
	./mx_print_dname.o \
	./mx_is_allowed.o \
	./mx_R.o \
	./mx_get_total.o \
	./mx_read.o \
		

OBJO = ./obj/main.o \
	./obj/mx_get_current_flags.o \
	./obj/mx_count_flags.o \
	./obj/mx_fill_errors.o \
	./obj/mx_fill_files.o \
	./obj/mx_get_permissions.o \
	./obj/mx_fill_dirs.o \
	./obj/mx_priority.o \
	./obj/mx_sorty.o \
	./obj/mx_checksort.o \
	./obj/mx_backsorty.o \
	./obj/mx_sort_str.o \
	./obj/mx_print_abcents.o \
	./obj/mx_print_files.o \
	./obj/mx_cat_output.o \
	./obj/mx_get_fileinfo.o \
	./obj/mx_get_acl.o \
	./obj/mx_get_owner.o \
	./obj/mx_get_group.o \
	./obj/mx_get_size.o \
	./obj/mx_get_size_h.o \
	./obj/mx_get_full_time.o \
	./obj/mx_get_short_time.o \
	./obj/mx_1_output.o \
	./obj/mx_m_output.o \
	./obj/mx_printname_f.o \
	./obj/mx_multicolumn_output.o \
	./obj/mx_long_output.o \
	./obj/mx_flong_out.o \
	./obj/mx_slong_out.o \
	./obj/mx_xattr.o \
	./obj/mx_acl.o \
	./obj/mx_get_controls.o \
	./obj/mx_space.o \
	./obj/mx_sizetoa.o \
	./obj/mx_get_max_size.o \
	./obj/mx_print_user.o \
	./obj/mx_print_permissions.o \
	./obj/mx_print_controls.o \
	./obj/mx_get_max_group.o \
	./obj/mx_get_max_owner.o \
	./obj/mx_get_max_links.o \
	./obj/mx_print_inode.o \
	./obj/mx_get_short_size.o \
	./obj/mx_def_space.o \
	./obj/mx_get_max_time.o \
	./obj/mx_print_dirs.o \
	./obj/mx_print_dname.o \
	./obj/mx_is_allowed.o \
	./obj/mx_R.o \
	./obj/mx_get_total.o \
	./obj/mx_read.o \
		
CFLGS = -std=c11 -Wall -Wextra -Wpedantic -Werror

all: install uninstall

install:
	@make -C libmx -f Makefile install
	@cp $(INC) $(SRCS) .
	@clang $(CFLGS) -c  $(SRC)
	@mkdir -p obj
	@mv $(OBJ) ./obj
	@clang $(CFLGS) $(OBJO) libmx/libmx.a -o $(NAME)

uninstall:
	@make -C libmx -f Makefile uninstall
	@rm -rf $(OBJO) $(SRC) $(HEADTMP)
	@rm -rf ./obj

clean: uninstall
	@make -C libmx -f Makefile clean
	@rm -rf $(NAME)

reinstall: clean all
