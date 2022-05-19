#include <unistd.h>

void	screen_control(void);

const char	*map_file_name = "../SCREEN_TXT_FILES/map.txt";
const char	*start_screen_file_name = "../SCREEN_TXT_FILES/start_screen.txt";
const char	*monster_slime_file_name = "../SCREEN_TXT_FILES/monster_slime.txt";
char		***map;
int			map_row_size;
int			map_col_size;

int	main(void)
{
	screen_control();
	return (0);
}
