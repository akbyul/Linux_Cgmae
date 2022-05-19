void	three_pointer_free(char ***arr, int	col_size, int row_size);

extern char	***map;
extern int	map_col_size;
extern int	map_row_size;

void    Release(void)
{
        three_pointer_free(map, map_col_size + 1, map_row_size + 1);
}
