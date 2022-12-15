#include <stdio.h>

int	main(int argc, char *argv[], char *envp[])
{
	int	i;

	i = -1;
	while(envp[++i])
		printf("envp[%d]: %s\n", i, envp[i]);
	return (0);
}
