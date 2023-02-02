/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 03:58:35 by dahkang           #+#    #+#             */
/*   Updated: 2023/02/03 03:55:45 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>



#include <sys/time.h>
#include "philos.h"

// retrun value: unit of time is micro
int	get_cur_time(void)
{
	struct timeval	tp;
	int				cur_time;

	gettimeofday(&tp, NULL);
	cur_time = tp.tv_sec * 1000000 + tp.tv_usec;
	return (cur_time);
}

int	get_elapsed_time(int time_from)
{
	return (get_cur_time() - time_from);
}

// unit of param is microsec
void	ft_usleep(int time)
{
	// int	start_time;
	// int	wait;

	printf("%s, time: %d\n", __func__, time);
	usleep(time);
	// wait = 0.3 * time;
	// start_time = get_cur_time();
	// while (get_elapsed_time(start_time) < wait)
		// usleep(200);
}

// TODO: all_done에 대한 별도 뮤텍스 필요한지 고민
void	print_msg(char *str, int id, t_args *args)
{
	int	time;

	time = get_elapsed_time(args->start_time) / 1000;
	//pthread_mutex_lock(&args->msg_lock);
	pthread_mutex_lock(&args->common);
	if (args->all_done == FALSE)
		printf("%d %d %s\n", time, id, str);
	//pthread_mutex_unlock(&args->msg_lock);
	pthread_mutex_unlock(&args->common);
}