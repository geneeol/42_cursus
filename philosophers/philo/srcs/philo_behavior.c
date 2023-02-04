/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 03:41:05 by dahkang           #+#    #+#             */
/*   Updated: 2023/02/05 00:34:04 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	pick_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	print_state("has taken a fork", philo->id, \
							philo->args);
	pthread_mutex_lock(philo->rfork);
	print_state("has taken a fork", philo->id, \
							philo->args);
}

void	put_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
}

void	thinking(t_philo *philo)
{
	print_state("is thinking", philo->id, philo->args);
}

// TODO: print_state랑 mutex_lock 순서 바꿔서 테스트
void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->args->personal + philo->id);
	philo->last_eat_time = get_cur_time();
	pthread_mutex_unlock(philo->args->personal + philo->id);
	print_state("is eating", philo->id, philo->args);
	if (philo->args->rules->n_must_eat != -1)
	{
		pthread_mutex_lock(philo->args->personal + philo->id);
		philo->eat_cnt++;
		pthread_mutex_unlock(philo->args->personal + philo->id);
	}
	ft_usleep(philo->args->rules->time_eat);
}

void	sleeping(t_philo *philo)
{
	print_state("is sleeping", philo->id, philo->args);
	ft_usleep(philo->args->rules->time_sleep);
}