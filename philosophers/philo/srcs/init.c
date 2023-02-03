/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 04:11:29 by dahkang           #+#    #+#             */
/*   Updated: 2023/02/03 14:39:35 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "philos.h"
#include "structures.h"


#include <stdio.h>

static int	abort_init(t_philo *philos, t_args *args, int err_code)
{
	free(philos);
	free(args->fork);
	free(args->personal);
	return (err_code);
}

static int	destroy_mutexs(t_args *args, int n_philo)
{
	int	i;

	pthread_mutex_destroy(&args->msg_lock);
	pthread_mutex_destroy(&args->common);
	i = 0;
	while (++i <= n_philo)
	{
		pthread_mutex_destroy(args->fork + i);
		pthread_mutex_destroy(args->personal + i);
	}
	return (CODE_ERROR_GENERIC);
}

static int	init_mutexes(t_args *args, int n_philo)
{
	int	i;

	if (pthread_mutex_init(&args->msg_lock, NULL) != 0
		|| pthread_mutex_init(&args->common, NULL) != 0)
		return (destroy_mutexs(args, n_philo));
	i = 0;
	while (++i <= n_philo)
	{
		if (pthread_mutex_init(args->fork + i, NULL) != 0
			|| pthread_mutex_init(args->personal + i, NULL) != 0)
			return (destroy_mutexs(args, n_philo));
	}
	return (CODE_OK);
}

// 필로 각각이 마지마긍로 먹은 시간을 기억해야함
// 그 시간에 접근하는게 필로 자기자신이 있고, 모니터링 쓰레드가 있음
//
int	init(t_philo **philos, t_args *args, t_rules *rules)
{
	int				i;

	*philos = malloc(sizeof(t_philo) * (rules->n_philo + 1));
	args->fork = malloc(sizeof(pthread_mutex_t) * (rules->n_philo + 1));
	args->personal = malloc(sizeof(pthread_mutex_t) * (rules->n_philo + 1));
	if (!philos || !args->fork || !args->personal)
		return (abort_init(*philos, args, CODE_ERROR_MALLOC));
	memset(*philos, 0, sizeof(t_philo) * (rules->n_philo + 1));
	memset(args->fork, 0, sizeof(pthread_mutex_t) * (rules->n_philo + 1));
	memset(args->personal, 0, \
			sizeof(pthread_mutex_t) * (rules->n_philo + 1));
	args->rules = rules;
	if (init_mutexes(args, rules->n_philo) != CODE_OK)
		return (abort_init(*philos, args, CODE_ERROR_GENERIC));
	i = 0;
	// TODO: n_philo 
	while (++i <= rules->n_philo)
	{
		(*philos)[i].id = i;
		(*philos)[i].args = args;
		if (i >= rules->n_philo)
			(*philos)[i].lfork = args->fork + 1;
		else
			(*philos)[i].lfork = args->fork + i + 1;
		(*philos)[i].rfork = args->fork + i;
	}
	return (CODE_OK);
}