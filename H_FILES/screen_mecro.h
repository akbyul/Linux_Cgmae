#ifndef SCREEN_MECRO_H
# define SCREEN_MECRO_H

#include "file_struct.h"
#include "node_mecro.h"

int		create_object(t_file *file);
void	delete_object(t_file *file);

# define CREATE_OBJECT(x)	SCREEN_SEARCH(x)		\
							if(create_object(curr))	\
								return (3);
# define DELETE_OBJECT(x)	SCREEN_SEARCH(x)		\
							delete_object(curr);

#endif
