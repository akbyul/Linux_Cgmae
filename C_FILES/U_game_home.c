#include "../H_FILES/screen_mecro.h"

void	Render(void);
int		cursor_control(int set_col, int gap, int line_number, int div_row);

extern int	col_count;
extern int	row_count;

int	U_game_home(void)
{
	t_file	*curr;

	DELETE_ALL;
	CREATE_OBJECT("game_home.txt");
	if (cursor_control(10, 2, 7, 1))
		return (1);
	return (0);
}
