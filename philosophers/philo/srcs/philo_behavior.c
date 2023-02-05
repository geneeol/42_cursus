/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 03:41:05 by dahkang           #+#    #+#             */
/*   Updated: 2023/02/05 14:49:16 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	pick_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	print_state("has taken a fork", philo);
	pthread_mutex_lock(philo->rfork);
	print_state("has taken a fork", philo);
}

void	put_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
}

void	thinking(t_philo *philo)
{
	print_state("is thinking", philo);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->shared->personal + philo->id);
	philo->last_eat_time = get_cur_time();
	pthread_mutex_unlock(philo->shared->personal + philo->id);
	print_state("is eating", philo);
	if (philo->shared->rules->n_must_eat != -1)
	{
		pthread_mutex_lock(philo->shared->personal + philo->id);
		philo->eat_cnt++;
		pthread_mutex_unlock(philo->shared->personal + philo->id);
	}
	ft_usleep(philo->shared->rules->time_eat);
}

void	sleeping(t_philo *philo)
{
	print_state("is sleeping", philo);
	ft_usleep(philo->shared->rules->time_sleep);
}
