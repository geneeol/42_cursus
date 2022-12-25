/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:02:23 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/26 00:40:04 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_syscalls.h"
#include "../includes/fdf.h"
#include "../includes/mlx.h"
#include "../libft/includes/libft.h"

/*
void	matrix_trans(t_transed_map *map_proj, const t_map *map_info)
{
	int		y;
	int		x;

	y = -1;
	while (++y < map_proj->height)
	{
		x = -1;
		while (++x < map_proj->width)
		{

		}
	}
}
*/

/*
t_transed_map	*transmap(const t_map *map_info)
{
	t_transed_map	*map_proj;
	int				y;

	map_proj = (t_transed_map *)ft_malloc(sizeof(t_transed_map));
	map_proj->width = map_info->width;
	map_proj->height = map_info->height;
	map_proj->v_arr = (t_vertex **)ft_malloc(sizeof(t_vertex *) * map_proj->height);
	y = -1;
	while (++y < map_proj->height)
		map_proj->v_arr[y] = (t_vertex *)ft_malloc(sizeof(t_vertex) * map_proj->height);
	matrix_trans(map_proj, map_info);
}
*/

int	main(int argc, char *argv[])
{
	t_mlx	*mlx_info;

	mlx_info = ft_mlx_init();
	mlx_info->map = map_input_parser(argv[1]);
	//map_projection(map, mlx_info);
	mlx_key_hook(mlx_info->win_ptr, key_hook, mlx_info);
	mlx_loop(mlx_info->mlx_ptr);
}
