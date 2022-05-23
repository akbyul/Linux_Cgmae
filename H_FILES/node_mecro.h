#ifndef NODE_MECRO_H
# define NODE_MECRO_H

#include "file_struct.h"
#include "file_dir.h"

int		is_null(void *);
char	*ft_str_join(char *src1, char *src2);
t_file	*search_node(char *name);

# define SCREEN_SEARCH(x)	curr = search_node(ft_str_join(SCREEN_DIR, x));	\
							if (is_null(curr))								\
								return (4);
#endif
