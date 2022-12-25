/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 00:49:55 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/26 01:16:51 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/fdf.h"
#include "../includes/ft_syscalls.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	my_put_pixel(int x, int y, t_mlx *mlx_info)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = mlx_info->img_addr + (y * mlx_info->size_l + x * (mlx_info->bpp / 8));
	*(unsigned int *)dst = 0x0000FF00;
}

static void	plot_line(t_vertex *v1, t_vertex *v2, t_mlx *mlx_info)	
{
	const int	dx = ft_abs(v1->x - v2->x);
	const int	dy = -ft_abs(v1->y - v2->y);
	const int	sx = 2 * (v1->x < v2->x) - 1;
	const int	sy = 2 * (v1->y < v2->y) - 1;
	int			err[2];

	err[0] = dx + dy;
	while (1)
	{
		my_put_pixel(v1->x, v1->y, mlx_info);
		if (v1->x == v2->x && v1->y == v2->y)
			break ;
		err[1] = 2 * err[0];
		if (err[1] >= dy)
		{
			if (v1->x == v2->x)
				break ;
			err[0] += dy;
			v1->x += sx;
		}
		if (err[1] <= dx)
		{
			if (v1->y == v2->y)
				break ;
			err[0] += dx;
			v1->y += sy;
		}
	}
}

static t_vertex	*transform(int x, int y, t_mlx *mlx_info)
{
	const t_map	*map = mlx_info->map;
	const t_vars *vars = mlx_info->vars;
	t_vertex	*v;

	v = ft_malloc(sizeof(t_vertex));
	v->x = x * map->dist * vars->x_scale;
	v->y = y * map->dist * vars->y_scale;
	v->z = map->map_org[y][x] * map->dist * vars->z_scale;
	//rotate_y(v, vars->beta);
	//rotate_x(v, vars->alpha);
	//rotate_z(v, vars->gamma);
	v->x += vars->x_translate + WIN_WIDTH / 2;
	v->y += vars->y_translate + WIN_HEIGHT / 2;
	return (v);
}

void	draw_img(t_mlx *mlx_info)
{
	int	y;
	int	x;

	set_mlx_img(mlx_info);
	y = -1;
	while (++y < mlx_info->map->height)
	{
		x = -1;
		while (++x < mlx_info->map->width)
		{
			if (x < mlx_info->map->width - 1)
				plot_line(transform(x, y, mlx_info),\
						transform(x + 1, y, mlx_info), mlx_info);
			if (y < mlx_info->map->height)
				plot_line(transform(x, y, mlx_info),\
						transform(x, y + 1, mlx_info), mlx_info);
		}
	}
}
