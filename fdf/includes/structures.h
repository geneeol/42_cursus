/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:29:22 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/25 22:54:50 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_vertex
{
	int	x;
	int	y;
	int	z;
}	t_vertex;

typedef struct s_map
{
	int		width;
	int		height;
	int		dist;
	int		**map_org;
	t_vertex	**map_proj;
}	t_map;

typedef struct s_vars
{
	double	alpha;
	double	beta;
	double	gamma;
	int		x_scale;
	int		y_scale;
	int		z_scale;
	int		x_translate;
	int		y_translate;
}	t_vars;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_addr;
	int		size_l;
	int		bpp;
	int		endian;
	t_map	*map;
	t_vars	*vars;
}	t_mlx;

typedef struct s_transed_map
{
	int			width;
	int			height;
	t_vertex	**v_arr;
}	t_transed_map;


typedef struct s_mat33
{
	double	m[3][3];
}	t_mat33;

#endif
