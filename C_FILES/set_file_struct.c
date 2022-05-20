#include <stdlib.h>
#include "../H_FILES/file_struct.h"

int		is_null(void *arr);
int		check_file_size(t_file *file);
int		error_comment(int check);
void	one_pointer_free(void *arr);

t_file	*set_file_struct(char *file_name, int set_col, int set_row)
{
	t_file	*file = malloc(sizeof(t_file));
	if (error_comment(is_null(file)))
		return (0);
	file->name = file_name;
	file->set_col = set_col;
	file->set_row = set_row;
	file->col_size = 0;
	file->row_size = 0;
	if (error_comment(check_file_size(file)))
	{
		one_pointer_free(file);
		return (0);
	}
	return (file);
}
