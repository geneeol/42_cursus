/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:18:31 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/20 21:41:01 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/fcntl.h>
#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line_bonus.h"

static int**	map_init(int width, int height, char *file_name)
{
	int	**map;
	int	fd;
	int	y;
	int	x;
	
	map = (int **)ft_malloc(sizeof(int *) * height);
	y = -1;
	while (++y < height)
		map[y] = (int *)ft_malloc(sizeof(int) * width);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_perror_exit("Failed to open file");
	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
	}
}

static int	ft_calc_width(char *line)
{
	char	**strs;
	int		width;

	strs = ft_split(line, ' ');
	if (!strs)
		ft_perror_exit("Failed to split");
	width = 0;
	while (strs[width])
		width++;
	if (strs[width - 1][0] == '\n')
		ft_perror_exit("Map error");
	free_strs(strs);
	return (width);
}

static int	get_map_size(char *file_name, int *width, int *height)
{
	char	*line;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_perror_exit("Failed to open file");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (*width == 0)
			*width = ft_width(line);
		else
			if (*width != ft_calc_width(line))
				ft_perror_exit("Map error");
		(*height)++;
		free(line);
	}
	close(fd);
}

int	**map_parser(char *file_name)
{
	int	**map;
	int	width;
	int	height;

	width = 0;
	height = 0;
	get_map_size(file_name, &width, &height);
	map = map_init(width, height, file_name);
