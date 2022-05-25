#include "../H_FILES/screen_mecro.h"
#include <stdio.h>

void	Render(void);

int	U_game_start(void)
{
	t_file	*curr;

	DELETE_ALL;
	printf("1\n");
	CREATE_OBJECT("game_start_state.txt");
	printf("1\n");
	CREATE_OBJECT("game_start_road.txt");
	printf("1\n");

	CREATE_OBJECT("user_job.txt");
	Render();
	return (0);
}
