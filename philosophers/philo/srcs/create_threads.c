/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 03:54:04 by dahkang           #+#    #+#             */
/*   Updated: 2023/02/07 14:55:43 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include "philos.h"

t_bool	is_done(t_philo *philo)
{
	t_bool	is_done;	

	pthread_mutex_lock(&philo->shared->common);
	is_done = philo->shared->all_done;
	pthread_mutex_unlock(&philo->shared->common);
	return (is_done);
}

static void	*only_one_philo(t_philo *philo)
{
	print_state("is thinking", philo);
	pthread_mutex_lock(philo->lfork);
	print_state("has taken a fork", philo);
	ft_usleep(philo->shared->rules->time_die);
	pthread_mutex_unlock(philo->lfork);
	return (NULL);
}

static void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->shared->common);
	pthread_mutex_unlock(&philo->shared->common);
	philo->_each_start_time = get_cur_time();
	philo->last_eat_time = philo->_each_start_time;
	if (philo->shared->rules->n_philo == 1)
		return (only_one_philo(philo));
	if ((philo->id & 1) == 1)
		usleep(philo->shared->rules->time_eat / 2);
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
	while (++i <= philos->shared->rules->n_philo)
		pthread_detach((philos + i)->tid);
	return (err_code);
}

int	create_threads(t_philo *philos, t_shared *shared)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&shared->common);
	while (++i <= shared->rules->n_philo)
	{
		if (pthread_create(&(philos + i)->tid, NULL, routine, philos + i) != 0)
			return (abort_create_threads(philos, CODE_ERROR_GENERIC));
	}
	shared->start_time = get_cur_time();
	pthread_mutex_unlock(&shared->common);
	usleep(shared->rules->time_die * 0.7);
	return (CODE_OK);
}
