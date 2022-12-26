/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 00:49:55 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/27 05:51:13 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../includes/fdf.h"
#include "../includes/ft_syscalls.h"
#include "../libft/includes/libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	my_put_pixel(int x, int y, int z, t_mlx *mlx_info)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = mlx_info->img_addr + (y * mlx_info->size_l + x * (mlx_info->bpp / 8));
	*(unsigned int *)dst = 0x00FFFFFF;
}

//too many lines
static void	plot_line(t_point *p1, t_point *p2, t_mlx *mlx_info)
{
	const int	dx = ft_abs(p1->x - p2->x);
	const int	dy = -ft_abs(p1->y - p2->y);
	const int	sx = 2 * (p1->x < p2->x) - 1;
	const int	sy = 2 * (p1->y < p2->y) - 1;
	int			err[2];

	err[0] = dx + dy;
	while (1)
	{
		my_put_pixel(p1->x, p1->y, p1->z, mlx_info);
		if (p1->x == p2->x && p1->y == p2->y)
			break ;
		err[1] = 2 * err[0];
		if (err[1] >= dy)
		{
			if (p1->x == p2->x)
				break ;
			err[0] += dy;
			p1->x += sx;
		}
		if (err[1] <= dx)
		{
			if (p1->y == p2->y)
				break ;
			err[0] += dx;
			p1->y += sy;
		}
	}
	free(p1);
	free(p2);
}

static t_point	*transform(int x, int y, t_mlx *mlx_info)
{
	const t_map		*map = mlx_info->map;
	const t_vars	*vars = mlx_info->vars;
	t_vertex		v;
	t_point			*p;

	p = ft_malloc(sizeof(t_point));
	v.x = x * map->dist * vars->x_scale;
	v.y = y * map->dist * vars->y_scale;
	v.z = map->map_org[y][x] * map->dist * vars->z_scale;
	rotate_x(&v, vars->alpha);
	rotate_y(&v, vars->beta);
	rotate_z(&v, vars->gamma);
	v.x += vars->x_translate + WIN_WIDTH / 2.0;
	v.y += vars->y_translate + WIN_HEIGHT / 2.0;
	p->x = v.x;
	p->y = v.y;
	p->z = v.z;
	return (p);
}

int	draw_img(t_mlx *mlx_info)
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
				plot_line(transform(x, y, mlx_info), \
						transform(x + 1, y, mlx_info), mlx_info);
			if (y < mlx_info->map->height - 1)
				plot_line(transform(x, y, mlx_info), \
						transform(x, y + 1, mlx_info), mlx_info);
		}
	}
	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, \
							mlx_info->img_ptr, 0, 0);
	return (1);
}
