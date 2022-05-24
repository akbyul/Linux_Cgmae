#include "../H_FILES/screen_mecro.h"

int		input_name(void);
int		cursor_control(int set_col, int gap, int line_number, int div_row);
void	Render(void);

extern int	col_count;
extern int	row_count;

#include <stdio.h>
int	U_new_game(void)
{
	t_file	*curr;

INPUT_NAME:
	DELETE_ALL;
	CREATE_OBJECT("new_game_1.txt");
	Render();
	if (input_name())
		return (6);
	CREATE_OBJECT("new_game_2.txt");
	CREATE_OBJECT("name.txt");
	cursor_control(16, 2, 2, 1);
	if (col_count == 1)
		goto INPUT_NAME;

//SELECT_JOB:
	DELETE_ALL;
	CREATE_OBJECT("new_game_3.txt");
	CREATE_OBJECT("new_game_3_slime.txt");
	CREATE_OBJECT("new_game_3_slime_stats.txt");
	CREATE_OBJECT("arrow_1.txt");
	CREATE_OBJECT("arrow_2.txt");
	Render();
//	if (selete_job())
//		return (7);

	return (0);
}
