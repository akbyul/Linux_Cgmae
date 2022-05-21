#include <stdlib.h>
#include "../H_FILES/file_struct.h"

int		is_null(void *arr);
int		error_comment(int check);
void	one_pointer_free(void *arr);

extern t_file	*screen_head;

t_file	*search_node(char *name)
{
	t_file	*curr;
	curr = screen_head;
	while (curr->next != NULL)
	{
		curr = curr->next;
		if (curr->name == name)
			return (curr);
	}
	error_comment(4);
	return (0);
}

void	add_node_in_the_end(t_file *file)
{
	t_file	*curr;
	curr = screen_head;
	while (curr->next != NULL)
		curr = curr->next;
	file->next = curr->next;
	curr->next = file;
}

int	head_node(void)
{
	screen_head = malloc(sizeof(t_file));
	if (error_comment(is_null(screen_head)))
		return (1);
	screen_head->next = NULL;
	screen_head->name = NULL;
	return (0);
}
