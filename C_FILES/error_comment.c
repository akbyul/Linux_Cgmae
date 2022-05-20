#include <stdio.h>

int	error_comment(int check)
{
	switch (check)
	{
	case 1:
		printf("MALLOC ERROR\n");
		return (1);
	case 2:
		printf("FILE ERROR\n");
		return (1);
	case 3:
		printf("FILE TO BUFFER ERROR\n");
		return (1);
	default:
		return (0);
	}
}
