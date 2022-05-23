#ifndef NODE_MECRO_H
# define NODE_MECRO_H

#include "file_struct.h"
#include "file_dir.h"

int		is_null(void *);
char	*ft_str_join(char *src1, char *src2);
t_file	*search_node(char *name);

# define SEARCH_SCREEN(x)	curr = search_node(ft_str_join(SCREEN_DIR, x));	\
							if (is_null(curr))								\
								return (4);

# define SEARCH_SCREEN1(x)	curr1 = search_node(ft_str_join(SCREEN_DIR, x));	\
							if (is_null(curr1))									\
								return (4);

# define SEARCH_SCREEN2(x)	curr2 = search_node(ft_str_join(SCREEN_DIR, x));	\
							if (is_null(curr2))									\
								return (4);

#endif
