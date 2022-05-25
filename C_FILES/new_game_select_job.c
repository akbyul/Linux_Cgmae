#include <stdio.h>
#include "../H_FILES/screen_mecro.h"
#include "../H_FILES/set_struct_mecro.h"

int		is_null(void *);
int		is_arrow_keys(void);
void	Render(void);

int	select_job(void)
{
	t_file		*curr;
	int			nkey;
	int			count;
	const int	max_count = 2;
	FILE		*fp = fopen("../SCREEN_TXT_FILES/user_job.txt", "w+");

	if (is_null(fp))
		return (1);
	fclose(fp);
	SET_SCREEN_STRUCT(job, "user_job.txt", 13, 28);
	SEARCH_SCREEN("user_job.txt");
	curr->col_size = 1;
	curr->row_size = 8;
	count = 0;
	nkey = 0;
	while (nkey != '\n')
	{
		switch (count)
		{
		case 0:
			DELETE_OBJECT("new_game_3_mung.txt");
			DELETE_OBJECT("new_game_3_mung_name.txt");
			DELETE_OBJECT("new_game_3_mung_stats.txt");

			CREATE_OBJECT("new_game_3_slime.txt");
			CREATE_OBJECT("new_game_3_slime_name.txt");
			CREATE_OBJECT("new_game_3_slime_stats.txt");
			break;
		case 1:
			DELETE_OBJECT("new_game_3_slime.txt");
			DELETE_OBJECT("new_game_3_slime_name.txt");
			DELETE_OBJECT("new_game_3_slime_stats.txt");

			CREATE_OBJECT("new_game_3_mung.txt");
			CREATE_OBJECT("new_game_3_mung_name.txt");
			CREATE_OBJECT("new_game_3_mung_stats.txt");
			break;
		}
		Render();

		nkey = is_arrow_keys();
		switch (nkey)
		{
		case 67:
			count++;
			break;
		case 68:
			count--;
			break;
		default:
			break;
		}
		if (count < 0)
			count += max_count;
		else if (count >= max_count)
			count -= max_count;
	
	}

	fp = fopen("../SCREEN_TXT_FILES/user_job.txt", "w+");
	if (is_null(fp))
		return (1);
	switch (count)
	{
	case 0:
		fprintf(fp, "%s", "Slime");
		break;
	case 1:
		fprintf(fp, "%s", "Mung");
		break;
	default:
		break;
	}
	fclose(fp);
	return (0);
}
