#include "../H_FILES/file_struct.h"

int		error_comment(int check);
int		set_head_node(void);
int		control_file_struct(void);
void	control_screen(void);
int		Release(void);

char	***map;
t_file	*screen_head;

int	main(void)
{
	if (set_head_node() == 0)
		if (control_file_struct() == 0)
			control_screen();
	if (error_comment(Release()))
		return (-1);
	return (0);
}
