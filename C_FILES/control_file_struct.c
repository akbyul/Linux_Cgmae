#include "../H_FILES/file_dir.h"
#include "../H_FILES/file_struct.h"

int		is_null(void *arr);
char	*ft_str_join(char *src1, char *src2);
t_file  *set_file_struct(char *file_name, int col_size, int row_size);

extern t_file  *map_file;
extern t_file  *start_screen_file;
extern t_file  *monster_slime_file;

int	 control_file_struct(void)
{
	map_file = set_file_struct(ft_str_join(txt_dir, "map.txt"), 0, 0);
	if (is_null(map_file))
		return (1);
	start_screen_file = set_file_struct(ft_str_join(txt_dir, "start_screen.txt"), 10, 15);
	if (is_null(start_screen_file))
		return (1);
	monster_slime_file = set_file_struct(ft_str_join(txt_dir, "monster_slime.txt"), 3, 20);
	if (is_null(monster_slime_file))
		return (1);
	return (0);
}
