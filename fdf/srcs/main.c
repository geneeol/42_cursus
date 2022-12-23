/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:02:23 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/23 21:31:21 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_syscalls.h"
#include "../includes/structures.h"
#include "../includes/fdf.h"
#include "../includes/mlx.h"

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

t_mlx	*ft_mlx_init()
{
	t_mlx	*mlx;

	mlx = (t_mlx *)ft_malloc(sizeof(t_mlx));
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Tiny FDF");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	mlx->img.data = (unsigned int *)mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp, &mlx->img.width, &mlx->img.endian);
	return (mlx);
}

int	main(int argc, char *argv[])
{
	const t_map		*map_info = map_parser(argv[1]);
	t_transed_map	*map_proj;
	t_mlx	*mlx;

	mlx = ft_mlx_init();
}
