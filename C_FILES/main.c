#include "../H_FILES/file_struct.h"
#include "../H_FILES/declare_file_struct.h"

int		control_file_struct(void);
void	control_screen(void);
void	Release(void);

char	***map;

int	main(void)
{
	if (control_file_struct() == 0)
		control_screen();
	Release();
	return (0);
}
