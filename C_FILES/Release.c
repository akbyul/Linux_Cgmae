#include "../H_FILES/file_struct.h"

int		is_null(void *arr);
void	one_pointer_free(void *arr);
void	three_pointer_free(void ***arr, int	col_size, int row_size);

extern char		***map;
extern t_file	*map_file;
extern t_file	*start_screen_file;
extern t_file	*monster_slime_file;

void    Release(void)
{
	if (!is_null((void *)map))
		three_pointer_free((void ***)map, map_file->col_size + 1, map_file->row_size + 1);
	if (!is_null((void *)map_file))
		one_pointer_free(map_file->name);
	if (!is_null((void *)start_screen_file))
		one_pointer_free(start_screen_file->name);
	if (!is_null((void *)monster_slime_file))
		one_pointer_free(monster_slime_file->name);
	one_pointer_free(map_file);
	one_pointer_free(start_screen_file);
	one_pointer_free(monster_slime_file);
}
