#include "../H_FILES/file_struct.h"

int		is_null(void *arr);
void	ft_memset(char *arr, int value, int size);
char	**file_to_buffer(t_file *file, int *size);
void	buffer_to_map(char **buffer, t_file *file);
void	two_pointer_free(void **arr, int size);

extern char	***map;

int	create_object(t_file *file)
{
	char	**buffer;
	int		size;

	buffer = file_to_buffer(file, &size);
	if (is_null(buffer))
		return (3);
	buffer_to_map(buffer, file);
	two_pointer_free((void **)buffer, size + 1);
	return (0);
}

void	delete_object(t_file *file)
{
	int	m, n;

	m = file->col_size;
	while (m--)
	{
		n = file->row_size;
		while (n--)
		{
			ft_memset(map[file->set_col + m][file->set_row + n], 0, 3);
			map[file->set_col + m][file->set_row + n][0] = ' ';
		}
	}
}
