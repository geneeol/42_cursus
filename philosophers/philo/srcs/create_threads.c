/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 03:54:04 by dahkang           #+#    #+#             */
/*   Updated: 2023/02/03 15:03:34 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"


#include <stdio.h>

t_bool	is_done(t_philo *philo)
{
	t_bool	is_done;	

	pthread_mutex_lock(&philo->args->common);
	is_done = philo->args->all_done;
	pthread_mutex_unlock(&philo->args->common);
	return (is_done);
}

// TODO: 먼저 잠자는 철학자들 상태를 다르게 표기해야하나?
static void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->args->common);
	pthread_mutex_unlock(&philo->args->common);
	if ((philo->id & 1) == 1)
		usleep(philo->args->rules->time_eat / 2);
	while (is_done(philo) != TRUE)
	{
		thinking(philo);
		pick_fork(philo);
		eating(philo);
		put_fork(philo);
		sleeping(philo);
	}
	return (NULL);
}

static int	abort_create_threads(t_philo *philos, int err_code)
{
	int	i;

	i = 0;
	while (++i <= philos->args->rules->n_philo)
		pthread_detach((philos + i)->tid);
	return (err_code);
}

// TODO: last_eat_time data_race 발생하지 않는지 체크
int	create_threads(t_philo *philos, t_args *args)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&args->common);
	while (++i <= args->rules->n_philo)
	{
		if (pthread_create(&(philos + i)->tid, NULL, routine, philos + i) != 0)
			return (abort_create_threads(philos, CODE_ERROR_GENERIC));
	}
	i = 0;
	args->start_time = get_cur_time();
	while (++i <= args->rules->n_philo)
		philos[i].last_eat_time = args->start_time;
	pthread_mutex_unlock(&args->common);
	return (CODE_OK);
}