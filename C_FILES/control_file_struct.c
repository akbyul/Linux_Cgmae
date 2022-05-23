#include "../H_FILES/file_dir.h"
#include "../H_FILES/file_struct.h"

int		is_null(void *arr);
char	*ft_str_join(char *src1, char *src2);
t_file  *set_file_struct(char *file_name, int col_size, int row_size);

int	 control_file_struct(void)
{
	t_file	*map_file = set_file_struct(ft_str_join(SCREEN_DIR, "map.txt"), 0, 0);
	if (is_null(map_file))
		return (1);
	t_file	*start_screen_file = set_file_struct(ft_str_join(SCREEN_DIR, "start_screen.txt"), 10, 19);
	if (is_null(start_screen_file))
		return (1);
	t_file	*monster_slime_file = set_file_struct(ft_str_join(SCREEN_DIR, "monster_slime.txt"), 3, 24);
	if (is_null(monster_slime_file))
		return (1);
	t_file	*new_or_load_file = set_file_struct(ft_str_join(SCREEN_DIR, "new_or_load.txt"), 10, 11);
	if (is_null(new_or_load_file))
		return (1);
	t_file	*press_the_arrow_keys_file = set_file_struct(ft_str_join(SCREEN_DIR, "press_the_arrow_keys.txt"), 30, 20);
	if (is_null(press_the_arrow_keys_file))
		return (1);
	t_file	*cursor_file_1 = set_file_struct(ft_str_join(SCREEN_DIR, "cursor1.txt"), 2, 2);
	if (is_null(cursor_file_1))
		return (1);
	t_file	*cursor_file_2 = set_file_struct(ft_str_join(SCREEN_DIR, "cursor2.txt"), 2, 2);
	if (is_null(cursor_file_2))
		return (1);
	return (0);
}
