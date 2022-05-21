#include <stdlib.h>
#include "../H_FILES/file_struct.h"
#include "../H_FILES/declare_file_struct.h"

int		is_null(void *arr);
void	one_pointer_free(void *arr);
void	three_pointer_free(void ***arr, int	col_size, int row_size);

extern char		***map;
extern t_file	*screen_head;

void    Release(void)
{
	t_file	*curr;
	
	three_pointer_free((void ***)map, map_file->col_size + 1, map_file->row_size + 1);
	curr = screen_head;
	while (curr != NULL)
	{
		t_file	*next = curr->next;
		one_pointer_free(curr->name);
		one_pointer_free(curr);
		curr = next;
	}
}
