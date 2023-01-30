/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 00:10:43 by dahkang           #+#    #+#             */
/*   Updated: 2023/01/31 04:13:24 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# include "structures.h"

# define TIME 0
# define ORIGIN 1
# define INT_MAX 2147483647

enum	e_returncode
{
	CODE_OK = 0,
	CODE_ERROR_GENERIC = -1,
	CODE_ERROR_IO = -2,
	CODE_ERROR_MALLOC = -3,
	CODE_ERROR_SCOPE = -4,
	CODE_ERROR_DATA = -5
};

int	parse_input(t_rules *info, int argc, char **argv);
int	init(t_philo **philos, t_args *args, t_rules *rules);

#endif
