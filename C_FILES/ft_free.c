#include <stdlib.h>

int	is_null(void *arr);

void	one_pointer_free(void *arr)
{
	if(!is_null(arr))
		free(arr);
}

void	two_pointer_free(void **arr, int size)
{
	int	i;

	i = 0;
	if (!is_null((void *)arr))
	{
		while (size--)
			one_pointer_free(arr[i++]);
		free(arr);
	}
}

void	three_pointer_free(void ***arr, int col_size, int row_size)
{
	int	i;

	i = 0;
	if (!is_null((void *)arr))
	{
		while (col_size--)
			two_pointer_free(arr[i++], row_size);
		free(arr);
	}
}
