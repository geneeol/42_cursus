/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 03:58:35 by dahkang           #+#    #+#             */
/*   Updated: 2023/02/05 16:53:07 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include "philos.h"

t_msec	get_cur_time(void)
{
	struct timeval	tp;
	t_msec			cur_time;

	gettimeofday(&tp, NULL);
	cur_time = tp.tv_sec * 1000000 + tp.tv_usec;
	return (cur_time);
}

t_msec	get_elapsed_time(t_msec time_from)
{
	return (get_cur_time() - time_from);
}

void	ft_usleep(t_msec time)
{
	t_msec	start_time;

	start_time = get_cur_time();
	usleep(time * 0.9);
	while (get_elapsed_time(start_time) < time)
		usleep(500);
}

void	print_die_and_mark_done(char *str, t_philo *philo)
{
	int	time;

	pthread_mutex_lock(&philo->shared->common);
	time = get_elapsed_time(philo->shared->start_time) / 1000;
	printf("%d %d %s\n", time, philo->id, str);
	philo->shared->all_done = TRUE;
	pthread_mutex_unlock(&philo->shared->common);
}

void	print_state(char *str, t_philo *philo)
{
	int	time;

	pthread_mutex_lock(&philo->shared->common);
	time = get_elapsed_time(philo->shared->start_time) / 1000;
	if (philo->shared->all_done == FALSE)
		printf("%d %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->shared->common);
}
