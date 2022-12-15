#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	printf("ret: %d\n", access(0, X_OK));
}
