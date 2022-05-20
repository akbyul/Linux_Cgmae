char	*memory_one_allocate(int size);
int		is_null(void *arr);

int	ft_strlen(char *arr)
{
	int	size;

	size = 0;
	while (arr[size])
		size++;
	return (size);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

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
	int	i;

	i = 0;
	while (i < size)
		arr[i++] = value;
}

char	*ft_str_join(char *src1, char *src2)
{
	char	*arr;
	int		size;
	int		i, k;

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
