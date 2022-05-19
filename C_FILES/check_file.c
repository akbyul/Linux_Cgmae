#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		is_null(void *);
char	**memory_two_allocate(int col_size, int row_size);
void	**two_pointer_free(char **arr, int size);
char	ft_strcpy(char *dest, char *src);

int	buffer_size(FILE *fp)
{
	int	size;

	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	return (size);
}

void	file_to_buffer(FILE *fp, char **buffer, int size)
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
		else
		{
			fread(buffer[i++], 1, 1, fp);
			size -= 1;
		}
	}
}

void	buffer_to_map(char ***map, char **buffer, int set_col, int set_row)
{
	int	i, m, n;

	i = 0;
	m = set_col;
	n = set_row;
	while (buffer[i][0])
	{
		ft_strcpy(map[m][n], buffer[i++]);
		n++;
		while (buffer[i][0] == '\n' && buffer[i][0])
		{
			i++;
			m++;
			n = set_row;
		}
	}
}

int	check_file_size(int *col_size, int *row_size, char *file_name)
{
	FILE	*fp;
	char	**buffer;
	int		size;
	int		check_row;
	int		i;

	fp = fopen(file_name, "r");
	if (is_null(fp))
		return (2);
	size = buffer_size(fp);
	buffer = memory_two_allocate(size + 1, 9);
	if (is_null(buffer))
		return (1);
	file_to_buffer(fp, buffer, size);

	i = 0;
	while (buffer[i][0])
	{
		check_row = 0;
		while (buffer[i][0] && buffer[i][0] != '\n')
		{
			check_row++;
			i++;
		}
		(*col_size)++;
		if (check_row > *row_size)
			*row_size = check_row;
		i++;
	}
	two_pointer_free(buffer, size + 1);
	fclose(fp);
	return (0);
}

int	set_file_to_map(char ***map, char *file_name, int set_col, int set_row)
{
	FILE	*fp;
	char	**buffer;
	int		size;

	fp = fopen(file_name, "r");
	if (is_null(fp))
		return (2);
	size = buffer_size(fp);
	buffer = memory_two_allocate(size + 1, 9);
	if (is_null(buffer))
		return (1);
	file_to_buffer(fp, buffer, size);
	buffer_to_map(map, buffer, set_col, set_row);
	two_pointer_free(buffer, size + 1);
	fclose(fp);
	return (0);
}
