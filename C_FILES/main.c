#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		_getch(void);
int		check_file_size(int *col_size, int *row_size, const char *file_name); 
int		is_null(void *arr);
char	***memory_three_allocate(int col_size, int row_size, int high_size);
void	***three_pointer_free(char ***arr, int col_size, int row_size);
int		set_file_to_map(char ***map, const char *file_name, int m, int n);

const char	*map_file_name = "../SCREEN_TXT_FILES/map.txt";
const char	*monster_slime_file_name = "../SCREEN_TXT_FILES/monster_slime.txt";
char		***map;
int			map_row_size;
int			map_col_size;

int	Init(void)
{
	map_row_size = 0;
	map_col_size = 0;
	if (check_file_size(&map_col_size, &map_row_size, map_file_name))
	{
		printf("FILE ERROR\n");
		return (1);
	}
	map = memory_three_allocate(map_col_size + 1, map_row_size + 1, 9);
	if (is_null((char *)map))
	{
		printf("MALLOC ERROR\n");
		return (1);
	}
	set_file_to_map(map, map_file_name, 0, 0);
	return (0);
}

int	Update(void)
{
	switch(set_file_to_map(map, monster_slime_file_name, 3, 20))
	{
	case 1:
		printf("FILE ERROR\n");
		return (1);
	case 2:
		printf("MALLOC ERROR\n");
		return (1);
	default:
		return (0);
	}
}

void	Render(void)
{
	int	m, n;

	m = 0;
	n = 0;
	write(1, "\033[1;1H\033[2J", 10);
	while (map[m][n][0])
	{
		while (map[m][n][0])
			printf("%s", map[m][n++]);
		printf("\n");
		n = 0;
		m++;
	}
}

void	Release(void)
{
	three_pointer_free(map, map_col_size + 1, map_row_size + 1);
}

int	main(void)
{
	char	nkey;

	Init();
/*	
	(void) nkey;
	Update();
	Render();
*/
	while (1)
	{
		read(0, &nkey, 1);
		switch (nkey)
		{
		case 'q':
			goto EXIT;
		case 's':
			Update();
			Render();
			break;
		default:
			break;
		}
	}
EXIT:
	Release();
	
	return (0);
}
