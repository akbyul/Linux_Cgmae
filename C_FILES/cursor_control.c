#include "../H_FILES/screen_mecro.h"

int		ft_getch(void);
int		is_enter(void);
int		is_arrow_keys(void);
void	Render(void);

int			col_count;
int			row_count;
extern char	***map;

int	cursor_control(int set_col, int gap, int line_number, int div_row)
{
	int		check_row;
	int		nkey;
	t_file	*curr;
	t_file	*curr1;
	t_file	*curr2;

	SEARCH_SCREEN("map.txt")
	SEARCH_SCREEN1("cursor_1.txt")
	SEARCH_SCREEN2("cursor_2.txt")
	
	col_count = 0;
	row_count = 0;
	nkey = 0;
	while (nkey != '\n')
	{
		curr1->set_col = set_col + (col_count * gap);
		curr2->set_col = set_col + (col_count * gap);
		check_row = 2 + (row_count * curr->row_size / div_row);
		while (map[set_col + (col_count * gap)][check_row][0] == ' ')
			check_row++;
		curr1->set_row = check_row - 4;
		check_row = curr->row_size - 3 - ((div_row - row_count - 1) * curr->row_size / div_row);
		if (gap < 0 && col_count == 1)
			check_row = curr->row_size - 3;
		while (map[set_col + (col_count * gap)][check_row][0] == ' ')
			check_row--;
		curr2->set_row = check_row + 3;
		CREATE_SOBJECT(curr1)
		CREATE_SOBJECT(curr2)
		Render();
		DELETE_SOBJECT(curr1)
		DELETE_SOBJECT(curr2)
		
		nkey = is_arrow_keys();
		if (nkey >= 65 && nkey <= 68)
		{
			switch (nkey)
			{
			case 65:
				col_count--;
				break;
			case 66:
				col_count++;
				break;
			case 67:
				row_count++;
				break;
			case 68:
				row_count--;
				break;
			default:
				break;
			}
			if (col_count < 0)
				col_count += line_number;
			else if (col_count >= line_number)
				col_count -= line_number;

			if (row_count < 0)
				row_count += div_row;
			else if (row_count >= div_row)
				row_count -= div_row;
		}
	}
	return (0);
}
