#include <unistd.h>
#include "../H_FILES/file_struct.h"

int	error_comment(int check);
int	create_object(t_file *file);

extern t_file	*monster_slime_file;

int	Update(void)
{
	char	nkey;

	read(0, &nkey, 1);
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
