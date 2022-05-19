#include <unistd.h>

int		Init(void);
int		Update(void);
void	Render(void);
void	Release(void);
int		map_reset(void);

void	screen_control(void)
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
	if (map_reset())
		return ;
//	if (start_screen())
//		return ;
	Render();
	while (1)
	{
		if (Update())
			break ;
		Render();
	}
	Release();
}
