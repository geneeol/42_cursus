#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	fd1;
	int	fd2;

	fd1 = open(".here_doc_tmp", O_CREAT | O_RDWR | O_TRUNC, 0666);
	fd2 = open("permission", O_CREAT | O_RDWR | O_TRUNC);
	printf("fd: %d\n", fd1);
	printf("fd: %d\n", fd2);
	return (0);
}
