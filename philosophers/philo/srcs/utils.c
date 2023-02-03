/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 03:58:35 by dahkang           #+#    #+#             */
/*   Updated: 2023/02/04 02:16:55 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>



#include <sys/time.h>
#include <unistd.h>
#include "philos.h"

// retrun value: unit of time is micro
uint64_t	get_cur_time(void)
{
	struct timeval	tp;
	uint64_t		cur_time;

	gettimeofday(&tp, NULL);
	cur_time = tp.tv_sec * 1000000 + tp.tv_usec;
	return (cur_time);
}

uint64_t	get_elapsed_time(uint64_t time_from)
{
	return (get_cur_time() - time_from);
}

// unit of param is microsec
void	ft_usleep(uint64_t time)
{
	uint64_t	start_time;

	start_time = get_cur_time();
	while (time - (get_elapsed_time(start_time)) > 1000)
		usleep(300);
	while (get_elapsed_time(start_time) < time)
		usleep(300);
}

// TODO: all_done에 대한 별도 뮤텍스 필요한지 고민
void	print_msg(char *str, int id, t_args *args)
{
	int	time;

	pthread_mutex_lock(&args->common);
	time = get_elapsed_time(args->start_time) / 1000;
	if (args->all_done == FALSE)
		printf("%d %d %s\n", time, id, str);
	pthread_mutex_unlock(&args->common);
}
