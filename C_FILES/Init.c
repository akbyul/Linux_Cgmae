#include "../H_FILES/screen_mecro.h"

char	***memory_three_allocate(int col_size, int row_size, int high_size);
int		is_enter(void);
void	Render(void);

extern char		***map;

int	Init(void)
{
	t_file	*curr;

	SEARCH_SCREEN("map.txt")
	map = memory_three_allocate(curr->col_size + 1, curr->row_size + 1, 5);
	if (is_null((char *)map))
		return (1);

	// game start screen
	CREATE_OBJECT("map.txt")
	CREATE_OBJECT("start_screen.txt")
	Render();

	while (!is_enter());

	// game init screen
	DELETE_OBJECT("start_screen.txt")

	CREATE_OBJECT("new_or_load.txt")
	CREATE_OBJECT("press_the_arrow_keys.txt")

	Render();

//	DELETE_OBJECT("press_the_arrow_keys.txt")
//	DELETE_OBJECT("new_or_save.txt")

	return (0);
}
