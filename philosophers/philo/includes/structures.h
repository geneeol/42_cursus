/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:32:38 by dahkang           #+#    #+#             */
/*   Updated: 2023/02/03 01:40:35 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <pthread.h>
# include <unistd.h>

# define TIME 0
# define ORIGIN 1
# define INT_MAX 2147483647

typedef int	t_bool;

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

// unit of time is microsec
typedef struct s_rules
{
	int	n_philo;
	int	time_die;		
	int	time_eat;		
	int	time_sleep;		
	int	n_must_eat;
}	t_rules;

typedef struct s_args
{
	t_rules				*rules;
	pthread_mutex_t		*fork;
	pthread_mutex_t		*personal;
	pthread_mutex_t		msg_lock;
	pthread_mutex_t		common;
	t_bool				all_done;
	int					start_time;
}	t_args;

typedef struct s_philo
{
	t_args			*args;
	int				id;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;
	pthread_t		tid;
	int				eat_cnt;
	int				last_eat_time;
	int				done;
}	t_philo;

#endif