#include <unistd.h>

int	error_comment(int check);
int	set_file_to_map(char ***map, char *file_name, int m, int n);

extern char	***map;
extern char	*monster_slime_file_name;

int	Update(void)
{
	char	nkey;

	read(0, &nkey, 1);
	switch (nkey)
	{
	case 'q':
		return (1);
	case 's':
		if (error_comment(set_file_to_map(map, monster_slime_file_name, 3, 20)))
			return (1);
	default:
		break;
	}
	return (0);
}
