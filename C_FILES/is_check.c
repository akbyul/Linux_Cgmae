#include <stdlib.h>

int	ft_getch(void);

int	is_null(void *arr)
{
	if (arr == NULL)
		return (1);
	else
		return (0);
}

int	is_enter(void)
{
	int	nkey;

	nkey = ft_getch();
	if (nkey == '\n')
		return (1);
	else
		return (0);
}
