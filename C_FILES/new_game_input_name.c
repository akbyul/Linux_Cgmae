#include <stdio.h>
#include "../H_FILES/set_struct_mecro.h"
#include "../H_FILES/screen_mecro.h"

char	*memory_one_allocate(int size);
void	one_pointer_free(void *arr);
int		ft_getch(void);
void	Render(void);

int	input_name(void)
{
	int		nkey;
	int		count;
	char	*arr;
	t_file	*curr;
	FILE	*fp = fopen("../SCREEN_TXT_FILES/user_name.txt", "w+");

	if (is_null(fp))
		return (1);
	fclose(fp);
	nkey = 0;
	count = 0;
	arr = memory_one_allocate(9);
	SET_SCREEN_STRUCT(name, "user_name.txt", 13, 30);
	SEARCH_SCREEN("user_name.txt");
	curr->col_size = 1;
	curr->row_size = 8;
	while (nkey != '\n')
	{
		nkey = ft_getch();
		if (nkey >= 'a' && nkey <= 'z' && count < 8)
		{
			arr[count] = nkey;
			count++;
		}
		else if (nkey == 127 && count != 0)
		{
			count--;
			arr[count] = 0;
		}
		fp = fopen("../SCREEN_TXT_FILES/user_name.txt", "w+");
		if (is_null(fp))
			return (1);
		fprintf(fp, "%s", arr);
		fclose(fp);
		SEARCH_SCREEN("user_name.txt");
		curr->set_row = 30 - (count / 2);
		CREATE_SOBJECT(curr);
		Render();
		if (nkey == '\n' && count < 2)
		{
			SEARCH_SCREEN("new_game_1_min.txt");
			CREATE_SOBJECT(curr);
			Render();
			DELETE_SOBJECT(curr);
			nkey = 0;
		}
		DELETE_SOBJECT(curr);
	}
	one_pointer_free(arr);
	return (0);
}
