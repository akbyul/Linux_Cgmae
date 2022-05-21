#ifndef FILE_STRUCT_H
# define FILE_STRUCT_H

typedef struct	s_file t_file;

struct	s_file {
	t_file	*next;
	char	*name;
	int		set_col;
	int		set_row;
	int		col_size;
	int		row_size;
};

#endif
