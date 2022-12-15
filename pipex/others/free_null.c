#include <stdlib.h>
#include <stdlib.h>

//null free해도 되네
int	main(void)
{
	char	*str = 0;

	free(str);
	return (0);
}
