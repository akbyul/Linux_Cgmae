#include "../H_FILES/file_struct.h"

int		head_node(void);
int		control_file_struct(void);
void	control_screen(void);
void	Release(void);

char	***map;
t_file	*screen_head;

int	main(void)
{
	if (head_node() == 0)
		if (control_file_struct() == 0)
			control_screen();
	Release();
	return (0);
}
