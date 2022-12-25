/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:06:40 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/26 00:39:41 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_WIDTH 1980
# define WIN_HEIGHT 1080

# include "structures.h"

t_mlx	*ft_mlx_init();
void	set_mlx_img(t_mlx *mlx_info);
t_map	*map_input_parser(char *file_name);

#endif
