#include <unistd.h>
#include "../H_FILES/file_struct.h"

int		Init(void);
int		Update(void);
void	Render(void);
void	Release(void);
void	delete_object(t_file *file);

extern t_file	*start_screen_file;

void	control_screen(void)
{
	char	nkey;

	// start
	if (Init())
		return ;
	Render();

	// Press Enter to Start
	nkey = 0;
	while (nkey != '\n')
		read(0, &nkey, 1);

	// game init screen
	delete_object(start_screen_file);
//	if (start_screen())
//		return ;
	Render();
	while (1)
	{
		if (Update())
			break ;
		Render();
	}
}
