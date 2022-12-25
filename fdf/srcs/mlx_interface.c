/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_interface.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 00:51:42 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/26 01:08:44 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../libft/includes/libft.h"
#include "../includes/fdf.h"
#include "../includes/mlx.h"
#include "../includes/ft_syscalls.h"


void	iso_proj(t_vars *vars)
{
	vars->alpha = asin(tan(M_PI / 6));
	vars->beta = M_PI_4;
	vars->gamma = 0;
	vars->x_scale = 1;
	vars->y_scale = 1;
	vars->z_scale = 1;
	vars->x_translate = 0;
	vars->y_translate = 0;
}

void	set_mlx_img(t_mlx *mlx_info)
{
	if (mlx_info->img_ptr)
		mlx_destroy_image(mlx_info->mlx_ptr, mlx_info->img_ptr);
	mlx_info->img_ptr = mlx_new_image(mlx_info->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (mlx_info->img_ptr)
		ft_perror_exit("Failed to creat a new image");
	mlx_info->img_addr = mlx_get_data_addr(mlx_info->img_ptr, &mlx_info->bpp, &mlx_info->size_l, &mlx_info->endian);
}

t_mlx	*ft_mlx_init()
{
	t_mlx	*mlx_info;

	mlx_info = (t_mlx *)ft_malloc(sizeof(t_mlx));
	ft_memset(mlx_info, 0, sizeof(t_mlx));
	mlx_info->mlx_ptr = mlx_init();
	if (!mlx_info->mlx_ptr)
		ft_perror_exit("Failed to initialize mlx");
	mlx_info->win_ptr = mlx_new_window(mlx_info->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "TINY FDF");
	if (!mlx_info->win_ptr)
		ft_perror_exit("Failed to create a new window");
	//mlx_info->img.img_ptr = mlx_new_image(mlx_info->mlx_ptr, W_SCALE, H_SCALE);
	//mlx_info->img.addr = mlx_get_data_addr(mlx_info->img.img_ptr, &mlx_info->img.bpp, &mlx_info->img.size_l, &mlx_info->img.endian);
	mlx_info->vars = ft_malloc(sizeof(t_vars));
	ft_memset(mlx_info->vars, 0, sizeof(t_vars));
	iso_proj(mlx_info->vars);
	return (mlx_info);
}
