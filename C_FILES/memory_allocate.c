#include <stdlib.h>

void	ft_memset(char *arr, int value, int size);

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
	ft_memset(arr, 0, size);
	return (arr);
}

char	**memory_two_allocate(volatile int col_size, volatile int row_size)
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

char	***memory_three_allocate(volatile int col_size, volatile int row_size, volatile int high_size)
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
