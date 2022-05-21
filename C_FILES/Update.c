#include "../H_FILES/file_struct.h"

int	ft_getch(void);
int	error_comment(int check);
int	create_object(t_file *file);

extern t_file	*monster_slime_file;

int	Update(void)
{
	char	nkey;

	nkey = ft_getch();
	switch (nkey)
	{
	case 'q':
		return (1);
	case 's':
		if (error_comment(create_object(monster_slime_file)))
			return (1);
	default:
		break;
	}
	return (0);
}
