/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 00:10:43 by dahkang           #+#    #+#             */
/*   Updated: 2023/01/30 02:49:57 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# include <pthread.h>
# include "t_input.h"

typedef struct s_args
{
	t_input				*input;
	pthread_mutex_t		*fork;
	int					start_flag;
	int					done;
	int					start_time;
}	t_args;

typedef struct s_philo
{
	t_args		*args;
	pthread_t	thread;
	int			id;
	int			left;
	int			right;
	int			n_eat;
}	t_philo;


enum	e_returncode
{
	CODE_OK = 0,
	CODE_ERROR_GENERIC = -1,
	CODE_ERROR_IO = -2,
	CODE_ERROR_MALLOC = -3,
	CODE_ERROR_SCOPE = -4,
	CODE_ERROR_DATA = -5
};

typedef int	t_bool;

int	parse_input(t_input *info, int argc, char **argv);

#endif
