/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 03:41:05 by dahkang           #+#    #+#             */
/*   Updated: 2023/02/03 16:10:51 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"


#include <stdio.h>

int	pick_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	print_msg("has taken a fork", philo->id, philo->args);
	pthread_mutex_lock(philo->rfork);
	print_msg("has taken a fork", philo->id, philo->args);
	return (CODE_OK);
}

int	put_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
	return (CODE_OK);
}

int	thinking(t_philo *philo)
{
	print_msg("is thinking", philo->id, philo->args);
	return (CODE_OK);
}

int	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->args->personal + philo->id);
	philo->last_eat_time = get_cur_time();
	pthread_mutex_unlock(philo->args->personal + philo->id);
	print_msg("is eating", philo->id, philo->args);
	ft_usleep(philo->args->rules->time_eat);
	pthread_mutex_lock(philo->args->personal + philo->id);
	if (philo->args->rules->n_must_eat != -1)
		philo->eat_cnt++;
	pthread_mutex_unlock(philo->args->personal + philo->id);
	return (CODE_OK);
}

int	sleeping(t_philo *philo)
{
	print_msg("is sleeping", philo->id, philo->args);
	ft_usleep(philo->args->rules->time_sleep);
	return (CODE_OK);
}