#include "get_next_line_bonus.h"
#include <stdio.h>

int	main(void)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		printf("str: %s\n", str);
		if (!str)
			return (printf("break\n"));
	}
	return (0);
	
}
