/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 00:10:43 by dahkang           #+#    #+#             */
/*   Updated: 2023/02/02 03:48:36 by dahkang          ###   ########.fr       */
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

enum	e_bool
{
	FALSE = 0,
	TRUE
};

int			parse_input(t_rules *info, int argc, char **argv);
int			init(t_philo **philos, t_args *args, t_rules *rules);

int			pick_fork(t_philo *philo);
int			put_fork(t_philo *philo);
int			thinking(t_philo *philo);
int			eating(t_philo *philo);
int			sleeping(t_philo *philo);

static void	*routine(void *arg);
static int	abort_create_threads(t_philo *philos, int err_code);
int			create_threads(t_philo *philos, t_args *args, t_rules *rules);
#endif
