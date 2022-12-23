/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:29:22 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/23 21:28:48 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H


typedef struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		width;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_mlx_info
{
	void	*mlx_ptr;
	void	*win;
	t_img	img;
}	t_mlx;

typedef struct s_vertex
{
	double	x;
	double	y;
	double	z;
}	t_vertex;

typedef struct s_transed_map
{
	int			width;
	int			height;
	t_vertex	**v_arr;
}	t_transed_map;

typedef struct s_map
{
	int	width;
	int	height;
	int	**map;
}	t_map;

typedef struct s_mat44
{
	double	m[4][4];
}	t_mat44;

#endif
