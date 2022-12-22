/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:18:31 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/23 01:41:31 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <fcntl.h>
#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line_bonus.h"
#include "../includes/ft_syscalls.h"
#include "../includes/structures.h"

static void	free_strs(char *strs[])
{
	int	i;

	if (!strs)
		return ;
	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
}

static void fill_map(int **map, int width, int height, char *file_name) 
{
	const int	fd = ft_open(file_name, O_RDONLY);
	char		*line;
	char		**strs;
	int			y;
	int			x;

	y = -1;
	while (++y < height)
	{
		x = -1;
		line = get_next_line(fd);
		strs = ft_split(line, ' ');
		if (!strs)
			ft_perror_exit("Failed to split");
		while (++x < width)
			map[y][x] = ft_atoi(strs[x]);
		free(line);
		free_strs(strs);
	}
	close(fd);
}

static t_map	*map_init(int width, int height, char *file_name)
{
	t_map	*map_info;
	int		y;

	map_info = ft_malloc(sizeof(t_map));
	map_info->width = width;
	map_info->height = height;
	map_info->map = (int **)ft_malloc(sizeof(int *) * height);
	y = -1;
	while (++y < height)
		map_info->map[y] = (int *)ft_malloc(sizeof(int) * width);
	fill_map(map_info->map, width, height, file_name);
	return (map_info);
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
		width--;
	free_strs(strs);
	return (width);
}

static void	get_map_size(char *file_name, int *width, int *height)
{
	const int	fd = ft_open(file_name, O_RDONLY);
	char		*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (*height == 0)
			*width = ft_calc_width(line);
		else
			if (*width != ft_calc_width(line))
				ft_perror_exit("Map error");
		(*height)++;
		free(line);
	}
	close(fd);
}

t_map	*map_parser(char *file_name)
{
	t_map	*map_info;
	int	width;
	int	height;

	width = 0;
	height = 0;
	get_map_size(file_name, &width, &height);
	map_info = map_init(width, height, file_name);
	return (map_info);
}
