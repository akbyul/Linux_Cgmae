#include <stdio.h>
#include "../H_FILES/screen_mecro.h"
#include "../H_FILES/game_start.h"

int		is_null(void *arr);
int		is_enter(void);
int		cursor_control(int set_col, int gap, int line_number, int div_row);
void	Render(void);

extern int	col_count;
extern int	row_count;

int	U_game_start(void)
{
	t_file	*curr;
	int		AP = 10;
	int		EL = 1;
	FILE	*fp;

	fp = fopen("../SCREEN_TXT_FILES/game_start_state.txt", "w+");
	if (is_null(fp))
		return (1);
	fprintf(fp, "AP : %d\n\n", AP);
	fprintf(fp, "EL : %d\n", EL);
	fclose(fp);
	
	DELETE_ALL;
	CREATE_OBJECT("game_start_state.txt");
	CREATE_OBJECT("game_stop.txt");
	CREATE_OBJECT("game_start_help.txt");
	Render();
	while (!is_enter());

	while (1)
	{
		DELETE_ALL;
		fp = fopen("../SCREEN_TXT_FILES/game_start_state.txt", "w+");
		if (is_null(fp))
			return (1);
		fprintf(fp, "AP : %d\n\n", AP);
		fprintf(fp, "EL : %d\n", EL);
		fclose(fp);
		CREATE_OBJECT("game_start_state.txt");
		CREATE_OBJECT("game_stop.txt");
		CREATE_OBJECT("user_job.txt");
		if (AP <= 0)
		{
			CREATE_OBJECT("game_over.txt");
			break;
		}
		CREATE_OBJECT("game_start_road.txt");

		if (cursor_control(10, -7, 2, 3))
			return (1);
		if (col_count == 1)
			;//
		else
		{
			switch (row_count)
			{
			case EASY:
				AP -= 1;
				break;
			case NORMAL:
				AP -= 1;
				EL += 5;
				break;
			case HARD:
				AP -= 1;
				EL += 20;
				break;
			default:
				break;
			}
		}
	}
	Render();
	return (0);
}
