#include <stdio.h>
#include <termios.h>

char	*memory_one_allocate(int size);
int		is_null(void *arr);

int	ft_getch(void)
{
	int				ch;
	struct termios	new, old;

	tcgetattr(0, &old);
	new = old;

	new.c_lflag &= !(ECHO | ICANON);
	new.c_cc[VMIN] = 1;
	new.c_cc[VTIME] = 0;
	tcsetattr(0, TCSAFLUSH, &new);
	ch = getchar();
	tcsetattr(0, TCSAFLUSH, &old);
	return (ch);
}

int	ft_strcmp(char *dest, char *src)
{
	int	i;

	i = 0;
	while (1)
	{
		if (dest[i] != src[i])
			return (dest[i] - src[i]);
		if (dest[i] == 0 && src[i] == 0)
			return (0);
		i++;
	}
}

int	ft_strlen(char *arr)
{
	volatile int	size;

	size = 0;
	while (arr[size])
		size++;
	return (size);
}

void	ft_strcpy(char *dest, char *src)
{
	volatile int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

void	ft_memset(char *arr, int value, int size)
{
	volatile int	i;

	i = 0;
	while (i < size)
		arr[i++] = value;
}

char	*ft_str_join(char *src1, char *src2)
{
	char			*arr;
	int				size;
	volatile int	i, k;

	size = ft_strlen(src1) + ft_strlen(src2);
	arr = memory_one_allocate(size + 1);
	if (is_null(arr))
		return (0);
	ft_memset(arr, 0, size + 1);
	i = 0;
	k = 0;
	while (src1[i])
	{
		arr[k] = src1[i];
		i++;
		k++;
	}
	i = 0;
	while (src2[i])
	{
		arr[k] = src2[i];
		i++;
		k++;
	}
	return (arr);
}
