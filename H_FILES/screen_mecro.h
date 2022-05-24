#ifndef SCREEN_MECRO_H
# define SCREEN_MECRO_H

#include "file_struct.h"
#include "node_mecro.h"

int		create_object(t_file *file);
void	delete_object(t_file *file);

# define CREATE_OBJECT(x)	SEARCH_SCREEN(x)			\
							if (create_object(curr))	\
								return (3);
# define DELETE_OBJECT(x)	SEARCH_SCREEN(x)			\
							delete_object(curr);

# define CREATE_SOBJECT(x)	if (create_object(x))		\
								return (3);
# define DELETE_SOBJECT(x)	delete_object(x);

# define DELETE_ALL			CREATE_OBJECT("map.txt");

#endif
