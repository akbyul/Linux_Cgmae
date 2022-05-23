int		Init(void);
int		Update(void);
void	Render(void);
int		error_comment(int check);

void	control_screen(void)
{
	if (error_comment(Init()))
		return ;
	if (error_comment(Update()))
		return ;
}
