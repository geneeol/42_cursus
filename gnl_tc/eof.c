#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

//eof에 닿기 직전까지 최대한 읽고
//eof에 닿았으면 그 다음에 0리턴

int	main(void)
{
	char	buf[15];
	int	fd;

	fd = open("file", O_RDONLY);
	printf("byte: %d\n", read(fd, buf, 5)); 
	printf("buf: %s\n", buf);
	for (int i = 0; i < 15; i++)
		printf("buf[%d]: %d\n", i, buf[i]);
	printf("byte: %d\n", read(fd, buf, 10)); 
	for (int i = 0; i < 15; i++)
		printf("buf[%d]: %d\n", i, buf[i]);
	printf("buf: %s\n", buf);
	printf("byte: %d\n", read(fd, buf, 10)); 
	printf("buf: %s\n", buf);
	return (0);
}
