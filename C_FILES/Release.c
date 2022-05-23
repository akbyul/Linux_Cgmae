#include <stdlib.h>
#include "../H_FILES/node_mecro.h"

int		is_null(void *arr);
void	one_pointer_free(void *arr);
void	three_pointer_free(void ***arr, int	col_size, int row_size);

extern char		***map;
extern t_file	*screen_head;

int	Release(void)
{
	t_file	*curr;
	
	SEARCH_SCREEN("map.txt")
	three_pointer_free((void ***)map, curr->col_size + 1, curr->row_size + 1);
	curr = screen_head;
	while (curr != NULL)
	{
		t_file	*next = curr->next;
		one_pointer_free(curr->name);
		one_pointer_free(curr);
		curr = next;
	}
	return (0);
}
