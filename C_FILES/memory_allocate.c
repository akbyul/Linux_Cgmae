#include <stdlib.h>
#include <string.h>

int	is_null(void *arr)
{
	if (arr == NULL)
		return (1);
	else
		return (0);
}

char	*memory_one_allocate(int size)
{
	char	*arr;

	arr = (char *)malloc(sizeof(char) * size);
	if (is_null(arr))
		return (0);
	memset(arr, 0, size);
	return (arr);
}

char	**memory_two_allocate(int col_size, int row_size)
{
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * col_size);
	if (is_null((char *)arr))
		return (0);
	while (col_size--)
	{
		arr[col_size] = memory_one_allocate(row_size);
		if (is_null(arr[col_size]))
			return (0);
	}
	return (arr);
}

char	***memory_three_allocate(int col_size, int row_size, int high_size)
{
	char	***arr;

	arr = (char ***)malloc(sizeof(char **) * col_size);
	if (is_null((char *)arr))
		return (0);
	while (col_size--)
	{
		arr[col_size] = memory_two_allocate(row_size, high_size);
		if (is_null((char *)arr[col_size]))
			return (0);
	}
	return (arr);
}
