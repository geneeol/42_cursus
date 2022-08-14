#define PATH ../get_next_line

#include "../get_next_line/get_next_line.h"
#include "../get_next_line/get_next_line.c"
#include "../get_next_line/get_next_line_utils.c"
#include <stdio.h>
#include <fcntl.h>

//eof에 닿기 직전까지 최대한 읽고
//eof에 닿았으면 그 다음에 0리턴

int	main(void)
{
	char	buf[15];
	int	fd;

	fd = open("file", O_RDONLY);
	printf("one line:%s\n", get_next_line(fd));
	return (0);
}
