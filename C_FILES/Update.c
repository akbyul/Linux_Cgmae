#include "../H_FILES/screen_mecro.h"
#include "../H_FILES/new_or_load.h"
#include "../H_FILES/game_home.h"

int		ft_getch(void);
void	Render(void);
int		cursor_control(int set_col, int gap, int line_number, int div_row);
int		U_new_game(void);
int		U_game_home(void);
int		U_game_start(void);

extern int	col_count;
extern int	row_count;

int	Update(void)
{
	int		nkey;
	t_file	*curr;

	// select new or load game
	if(cursor_control(11, 4, 3, 1))
		return (5);

	switch (col_count)
	{
	case NEW_GAME:
		if (U_new_game())
			return (6);
		break ;
	case LOAD_GAME:
		//
		break ;
	case EXIT_1:
		return (0);
	default:
		return (0);
	}

	// game home
//GAME HOME:
	if (U_game_home())
		return (7);
	switch (col_count)
	{
	case GAME_START:
		if (U_game_start())
			return (8);
		break;
	case EQUIP:
		break;
	case SKILL:
		break;
	case STORE:
		break;
	case PROFILE:
		break;
	case SAVE:
		break;
	case EXIT_2:
		break;
	default:
		break;
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
