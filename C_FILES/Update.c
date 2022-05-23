#include "../H_FILES/screen_mecro.h"
#include "../H_FILES/new_or_load.h"

int		ft_getch(void);
void	Render(void);
int		cursor_control(int set_col, int gap, int line_number);

int	Update(void)
{
	int		nkey;
	int		count;
	t_file	*curr;

	count = cursor_control(11, 4, 3);
	if (count > 0)
		return (5);
	switch (count)
	{
	case NEW_GAME:
		//
		break ;
	case LOAD_GAME:
		//
		break ;
	case EXIT:
		return (0);
	default:
		return (0);
	}
	while (1)
	{
		nkey = ft_getch();
		if (nkey == 'q')
			break;
		switch (nkey)
		{
		case 's':
			CREATE_OBJECT("monster_slime.txt")
			break;
		default:
			break;
		}
		Render();
	}
	return (0);
}
