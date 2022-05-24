#ifndef SET_STRUCT_MECRO_H
# define SET_STRUCT_MECRO_H

#include "file_struct.h"
#include "file_dir.h"

int		is_null(void *arr);
char	*ft_str_join(char *src1, char *src2);
t_file	*set_file_struct(char *file_name, int set_col, int set_row);

# define SET_SCREEN_STRUCT(x, y, m, n)	t_file *x = set_file_struct(ft_str_join(SCREEN_DIR, y), m, n);	\
										if (is_null(x))													\
											return (1);													\

#endif
