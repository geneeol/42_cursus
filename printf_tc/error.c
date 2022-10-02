#include <stdio.h>

int	main(void)
{
	printf("ret: %d\n", printf("hi%"));
	printf("ret: %d\n", printf("hi%", 'c'));
	return (0);
}
