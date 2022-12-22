#include "../includes/ft_syscalls.h"
#include "../includes/structures.h"
#include "../srcs/ft_perror_exit.c"
#include "../srcs/ft_syscalls.c"
#include "../srcs/map_parser.c"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_map	*map_info = map_parser(argv[1]);
	int	y;
	int	x;

	y = -1;
	while (++y < map_info->height)
	{
		x = -1;
		while (++x < map_info->width)
			printf("%d ", map_info->map[y][x]);
		printf("\n");
	}
	return (0);
}
