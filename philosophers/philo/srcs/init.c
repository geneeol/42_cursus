/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 04:11:29 by dahkang           #+#    #+#             */
/*   Updated: 2023/02/02 02:24:11 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "philos.h"


#include <stdio.h>

static int	abort_init(t_philo *philos, pthread_mutex_t *fork, int err_code)
{
	free(philos);
	free(fork);
	return (err_code);
}

static int	destroy_mutexs(t_args *args, int n_philo)
{
	int	i;

	pthread_mutex_destroy(&args->msg_lock);
	pthread_mutex_destroy(&args->info_lock);
	i = -1;
	while (++i < n_philo)
		pthread_mutex_destroy(args->fork + i);
	return (CODE_ERROR_GENERIC);
}

static int	init_mutexs(t_args *args, int n_philo)
{
	int	i;

	if (pthread_mutex_init(&args->msg_lock, NULL) != 0
		|| pthread_mutex_init(&args->info_lock, NULL) != 0)
		return (destroy_mutexs(args, n_philo));
	i = -1;
	while (++i < n_philo)
	{
		if (pthread_mutex_init(args->fork + i, NULL) != 0)
			return (destroy_mutexs(args, n_philo));
	}
	return (CODE_OK);
}

int	init(t_philo **philos, t_args *args, t_rules *rules)
{
	int				i;

	*philos = malloc(sizeof(t_philo) * (rules->n_philo + 1));
	args->fork = malloc(sizeof(pthread_mutex_t) * (rules->n_philo + 1));
	if (!philos || !args->fork)
		return (abort_init(*philos, args->fork, CODE_ERROR_MALLOC));
	memset(*philos, 0, sizeof(t_philo) * (rules->n_philo + 1));
	memset(args->fork, 0, sizeof(pthread_mutex_t) * (rules->n_philo + 1));
	args->rules = rules;
	if (init_mutexs(args, rules->n_philo) != CODE_OK)
		return (abort_init(*philos, args->fork, CODE_ERROR_GENERIC));
	i = 0;
	while (++i <= rules->n_philo)
	{
		(*philos)[i].id = i;
		(*philos)[i].args = args;
		(*philos)[i].lfork = args->fork + ((i + 1) % rules->n_philo);
		(*philos)[i].rfork = args->fork + i;
	}
	return (CODE_OK);
}