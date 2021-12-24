#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fpointer;
	char	*singleLine;
	int		i;

	fpointer = open("41_with_nl", 256);
	for (i = 0; i <= 5; i++)
	{
		singleLine = get_next_line(fpointer);
		printf("%s", singleLine);
		free(singleLine);
	}
	return (0);
}