#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	printf("access full_option: %d\n", access("/bin/ls -l", X_OK));
	printf("access no slash, but file_name: %d\n", access("exec", X_OK));
	return (0);
}
