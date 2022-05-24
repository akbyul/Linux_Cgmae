#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../H_FILES/file_struct.h"

int		is_null(void *);
char	**memory_two_allocate(int col_size, int row_size);
void	**two_pointer_free(char **arr, int size);
char	ft_strcpy(char *dest, char *src);

extern char	***map;

int	file_size(FILE *fp)
{
	int	size;

	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	return (size);
}

void	set_buffer(FILE *fp, char **buffer, int size)
{
	int		i;
	char	file_char;

	i = 0;
	while (size > 0)
	{
		file_char = fgetc(fp);
		fseek(fp, -1, SEEK_CUR);
		if (file_char == '\xf0' || file_char == '\x9f')
		{
			fread(buffer[i++], 2, 1, fp);
			size -= 2;
		}
		else if (file_char == '\xe2')
		{
			fread(buffer[i++], 5, 1, fp);
			size -= 5;
		}
		else
		{
			fread(buffer[i++], 1, 1, fp);
			size -= 1;
		}
	}
}

char	**file_to_buffer(t_file *file, int *size)
{
	FILE	*fp;
	char	**buffer;

	fp = fopen(file->name, "r");
	if (is_null(fp))
		return (0);
	*size = file_size(fp);
	buffer = memory_two_allocate(*size + 1, 5);
	if (is_null(buffer))
		return (0);
	set_buffer(fp, buffer, *size);
	fclose(fp);
	return (buffer);
}

int	check_file_size(t_file *file)
{
	char	**buffer;
	int		size;
	int		check_row;
	int		i;

	buffer = file_to_buffer(file, &size);
	if (is_null(buffer))
		return (3);
	i = 0;
	while (buffer[i][0])
	{
		check_row = 0;
		while (buffer[i][0] && buffer[i][0] != '\n')
		{
			check_row++;
			i++;
		}
		(file->col_size)++;
		if (check_row > file->row_size)
			file->row_size = check_row;
		i++;
	}
	two_pointer_free(buffer, size + 1);
	return (0);
}

void	buffer_to_map(char **buffer, t_file *file)
{
	int	i, m, n;

	i = 0;
	m = file->set_col;
	n = file->set_row;
	while (buffer[i][0])
	{
		ft_strcpy(map[m][n], buffer[i++]);
		n++;
		while (buffer[i][0] == '\n' && buffer[i][0])
		{
			i++;
			m++;
			n = file->set_row;
		}
	}
}
