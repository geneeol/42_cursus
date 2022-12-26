/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:06:40 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/27 04:08:51 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

# include <math.h>
# include "structures.h"

t_map	*map_input_parser(char *file_name);

t_mlx	*ft_mlx_init(void);
void	set_mlx_img(t_mlx *mlx_info);
int		key_hook(int key_code, t_mlx *mlx_info);

void	iso_proj(t_vars *vars);
void	parellel_proj(t_vars *vars);

int		draw_img(t_mlx *mlx_info);
void	rotate_y(t_vertex *v, double beta);
void	rotate_x(t_vertex *v, double alpha);
void	rotate_z(t_vertex *v, double gamma);

#endif
