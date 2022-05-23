#include "../H_FILES/screen_mecro.h"

int		ft_getch(void);
int		is_enter(void);
void	Render(void);

extern char	***map;

int	cursor_control(int set_col, int gap, int line_number)
{
	int		check_row;
	int		nkey;
	int		line_count;
	t_file	*curr;
	t_file	*curr1;
	t_file	*curr2;

	SEARCH_SCREEN("map.txt")
	SEARCH_SCREEN1("cursor1.txt")
	SEARCH_SCREEN2("cursor2.txt")
	
	line_count = 0;
	nkey = 0;
	while (nkey != '\n')
	{
		curr1->set_col = set_col + (line_count * gap);
		curr2->set_col = set_col + (line_count * gap);
		check_row = 2;
		while (map[set_col + (line_count * gap)][check_row][0] == ' ')
			check_row++;
		curr1->set_row = check_row - 4;
		check_row = curr->row_size - 3;
		while (map[set_col + (line_count * gap)][check_row][0] == ' ')
			check_row--;
		curr2->set_row = check_row + 3;
		CREATE_SOBJECT(curr1)
		CREATE_SOBJECT(curr2)
		Render();
		DELETE_SOBJECT(curr1)
		DELETE_SOBJECT(curr2)
		
		nkey = ft_getch();
		if (nkey == 27)
		{
			nkey = ft_getch();
			nkey = ft_getch();
			switch (nkey)
			{
			case 65:
				line_count--;
				break;
			case 66:
				line_count++;
				break;
			default:
				break;
			}
			if (line_count < 0)
				line_count += line_number;
			else if (line_count >= line_number)
				line_count -= line_number;
		}
	}
	return (-1 * line_count);
}
