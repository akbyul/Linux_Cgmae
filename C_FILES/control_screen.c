#include "../H_FILES/file_struct.h"
#include "../H_FILES/declare_file_struct.h"

int		ft_getch(void);
int		Init(void);
int		Update(void);
void	Render(void);
void	Release(void);
int		create_object(t_file *file);
void	delete_object(t_file *file);

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
		nkey = ft_getch();

	// game init screen
	delete_object(start_screen_file);
	if (create_object(new_or_save_file))
		return ;
	if (create_object(press_the_arrow_keys_file))
		return ;
	Render();
	while (1)
	{
		if (Update())
			break ;
		Render();
	}
}
