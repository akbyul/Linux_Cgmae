#include <stdio.h>
#include <unistd.h>

extern char	***map;

void    Render(void)
{
	int     m, n;

	m = 0;
	n = 0;
	write(1, "\033[1;1H\033[2J", 10);
	while (map[m][n][0])
	{
		while (map[m][n][0])
			printf("%s", map[m][n++]);
		printf("\n");
		n = 0;
		m++;
	}
}
