//#include "../H_FILES/file_dir.h"
#include "../H_FILES/file_struct.h"

int		is_null(void *arr);
char	***memory_three_allocate(int col_size, int row_size, int high_size);
int		error_comment(int check);
int		create_object(t_file *file);
char	*ft_str_join(char *src1, char *src2);
//t_file	*search_node(char *name);

extern char		***map;
extern t_file	*map_file;
extern t_file	*start_screen_file;

int	Init(void)
{
//	t_file	*curr;
	
//	curr = search_node(ft_str_join(screen_dir, "map.txt"));
	map = memory_three_allocate(map_file->col_size + 1, map_file->row_size + 1, 3);
//	map = memory_three_allocate(curr->col_size + 1, curr->row_size + 1, 3);
	if (is_null((char *)map))
	{
		error_comment(1);
		return (1);
	}
	if (error_comment(create_object(map_file)))
		return (1);
	if (error_comment(create_object(start_screen_file)))
		return (1);
	return (0);
}
