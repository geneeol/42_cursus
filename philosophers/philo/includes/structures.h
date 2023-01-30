/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:32:38 by dahkang           #+#    #+#             */
/*   Updated: 2023/01/31 05:47:06 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <pthread.h>
# include <unistd.h>

typedef struct s_rules
{
	int			n_philo;
	useconds_t	time_die;		
	useconds_t	time_eat;		
	useconds_t	time_sleep;		
	int			n_must_eat;
}	t_rules;

typedef struct s_args
{
	t_rules				*rules;
	pthread_mutex_t		*fork;
	pthread_mutex_t		msg_lock;
	pthread_mutex_t		mt_lock;
	int					is_start;
	int					is_done;
	int					start_time;
}	t_args;

typedef struct s_philo
{
	t_args			*args;
	int				id;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;
	pthread_t		thread;
	int				eat_cnt;
	int				done;
}	t_philo;

typedef int	t_bool;

#endif