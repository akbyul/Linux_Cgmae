#include "../H_FILES/file_struct.h"

int		control_file_struct(void);
void	control_screen(void);
void	Release(void);

char	***map;
t_file	*map_file;
t_file	*start_screen_file;
t_file	*monster_slime_file;

int	main(void)
{
	if (control_file_struct() == 0)
		control_screen();
	Release();
	return (0);
}
