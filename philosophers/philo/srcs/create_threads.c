/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 03:54:04 by dahkang           #+#    #+#             */
/*   Updated: 2023/02/02 04:16:28 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

static void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->args->info_lock);
	pthread_mutex_unlock(&philo->args->info_lock);
	if ((philo->id & 1) == 1)
		ft_usleep(proper_time);
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

// TODO: args 초기화 안해도 값이 0인지 확인. (static이라 0일 것임)
// TODO: 긴급, philos[1], philos[2]만 초기화 돼있는 상태라... 코드 조정이 필요함
int	create_threads(t_philo *philos, t_args *args, t_rules *rules)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&args->info_lock);
	while (++i <= rules->n_philo)
	{
		if (pthread_create(&(philos + i)->tid, NULL, routine, philos + i))
			return (abort_create_threads(philos, CODE_ERROR_GENERIC));
	}
	pthread_mutex_unlock(&args->info_lock);
	return (CODE_OK);
}