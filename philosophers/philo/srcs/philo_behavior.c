/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 03:41:05 by dahkang           #+#    #+#             */
/*   Updated: 2023/02/02 03:44:01 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// print_msg 함수 만들까? , 속도면에서 고민됨

#include "philos.h"

int	pick_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	\
	pthread_mutex_lock(&philo->args->msg_lock);
	printf("%dms %d has taken a fork\n", get_cur_time(), philo->id);
	pthread_mutex_unlock(&philo->args->msg_lock);
	\
	\
	pthread_mutex_lock(philo->rfork);
	\
	pthread_mutex_lock(&philo->args->msg_lock);
	printf("%dms %d has taken a fork\n", get_cur_time(), philo->id);
	pthread_mutex_unlock(&philo->args->msg_lock);
}

int	put_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
}

int	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->msg_lock);
	printf("%dms %d is thinking\n", get_cur_time(), philo->id);
	pthread_mutex_unlock(&philo->args->msg_lock);
}

int	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->msg_lock);
	philo->last_eat_time = get_cur_time();
	printf("%dms %d is eating\n", get_cur_time(), philo->id);
	pthread_mutex_unlock(&philo->args->msg_lock);
	\
	ft_usleep(philo->args->rules->time_eat);
}

// TODO: sleep을 mutex unlock 후에 하면 시간이 밀릴 수도
// TODO: get_curtime을 뮤텍스 락 이후에 시도하면 시간이 밀릴지도
int	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->msg_lock);
	printf("%dms %d is sleeping\n", get_cur_time(), philo->id);
	pthread_mutex_unlock(&philo->args->msg_lock);

	ft_usleep(philo->args->rules->time_sleep);
}