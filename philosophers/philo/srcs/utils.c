/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 03:58:35 by dahkang           #+#    #+#             */
/*   Updated: 2023/02/04 23:47:54 by dahkang          ###   ########.fr       */
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
		usleep(100);
}

void	print_die_and_mark_done(char *str, int id, t_args *args)
{
	int	time;

	pthread_mutex_lock(&args->common);
	time = get_elapsed_time(args->start_time) / 1000;
	printf("%d %d %s\n", time, id, str);
	args->all_done = TRUE;
	pthread_mutex_unlock(&args->common);
}

void	print_state(char *str, int id, t_args *args)
{
	int	time;

	pthread_mutex_lock(&args->common);
	time = get_elapsed_time(args->start_time) / 1000;
	if (args->all_done == FALSE)
		printf("%d %d %s\n", time, id, str);
	pthread_mutex_unlock(&args->common);
}