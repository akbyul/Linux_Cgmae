#include "../H_FILES/screen_mecro.h"

int		input_name(void);
int		select_job(void);
int		cursor_control(int set_col, int gap, int line_number, int div_row);
void	Render(void);

extern int	col_count;
extern int	row_count;

int	U_new_game(void)
{
	t_file	*curr;

INPUT_NAME:
	DELETE_ALL;
	CREATE_OBJECT("new_game_1.txt");
	Render();
	if (input_name())
		return (6);
	DELETE_ALL;
	CREATE_OBJECT("new_game_2_check.txt");
	CREATE_OBJECT("user_job_name.txt");
	cursor_control(16, 2, 2, 1);
	if (col_count == 1)
		goto INPUT_NAME;

SELECT_JOB:
	DELETE_ALL;
	CREATE_OBJECT("new_game_3.txt");
	CREATE_OBJECT("arrow_1.txt");
	CREATE_OBJECT("arrow_2.txt");
	if (select_job())
		return (6);
	DELETE_ALL;
	CREATE_OBJECT("new_game_4_check.txt");
	CREATE_OBJECT("user_job_name.txt");
	cursor_control(16, 2, 2, 1);
	if (col_count == 1)
		goto SELECT_JOB;

	return (0);
}
