#include "../H_FILES/file_struct.h"
#include "../H_FILES/declare_file_struct.h"

int		Init(void);
int		Update(void);
void	Render(void);
void	Release(void);
int		error_comment(int check);

void	control_screen(void)
{

	// start
	if (error_comment(Init()))
		return ;
	while (1)
	{
		if (Update())
			break ;
		Render();
	}
}
