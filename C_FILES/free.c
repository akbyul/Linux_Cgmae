#include <stdlib.h>

void	one_pointer_free(char *arr)
{
	free(arr);
}

void	two_pointer_free(char **arr, int size)
{
	int	i;

	i = 0;
	while (size--)
		one_pointer_free(arr[i++]);
	free(arr);
}

void	three_pointer_free(char ***arr, int col, int row)
{
	int	i;

	i = 0;
	while (col--)
		two_pointer_free(arr[i++], row);
	free(arr);
}
