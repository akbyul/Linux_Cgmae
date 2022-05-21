#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern char	***map;

void    Render(void)
{
	int     m, n;

	m = 0;
	n = 0;
	system("clear");
	while (map[m][n][0])
	{
		while (map[m][n][0])
			printf("%s", map[m][n++]);
		printf("\n");
		n = 0;
		m++;
	}
}
