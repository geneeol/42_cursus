#include <unistd.h>

int	main(int argc, char *argv[], char *envp[])
{
	char	*args[] = {"sleep", "1", 0};

	execve("/bin/sleep", args, envp);
}
