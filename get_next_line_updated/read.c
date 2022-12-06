#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	char	buf[100];
	int		rbyte;

	while (1)
	{
		rbyte = read(0, buf, 10);
		buf[rbyte] = 0;
		printf("buf: %s\n", buf);
		if (buf[0] == 0)
			return (printf("break\n"));
	}
	return (0);
}
