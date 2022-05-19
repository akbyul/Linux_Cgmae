void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
}

void	ft_memset(char *arr, int value, int size)
{
	int	i;

	i = 0;
	while (i < size)
		arr[i++] = value;
}
