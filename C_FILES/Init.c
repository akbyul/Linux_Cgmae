int		is_null(void *arr);
int		check_file_size(int *col_size, int *row_size, const char *file_name);
int		set_file_to_map(char ***map, char *file_name, int m, int n);
char	***memory_three_allocate(int col_size, int row_size, int high_size);
int		error_comment(int check);

extern char	***map;
extern char	*map_file_name;
extern char	*start_screen_file_name;
extern int	map_row_size;
extern int	map_col_size;

int	Init(void)
{
	map_row_size = 0;
	map_col_size = 0;
	if (error_comment(check_file_size(&map_col_size, &map_row_size, map_file_name)))
		return (1);
	map = memory_three_allocate(map_col_size + 1, map_row_size + 1, 3);
	if (is_null((char *)map))
	{
		error_comment(1);
		return (1);
	}
	if (error_comment(set_file_to_map(map, map_file_name, 0, 0)))
		return (1);
	if (error_comment(set_file_to_map(map, start_screen_file_name, 10, 15)))
		return (1);
	return (0);
}

int	map_reset(void)
{
	if (error_comment(set_file_to_map(map, map_file_name, 0, 0)))
		return (1);
	return (0);
}
