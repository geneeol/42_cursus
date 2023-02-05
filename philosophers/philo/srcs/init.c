/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 04:11:29 by dahkang           #+#    #+#             */
/*   Updated: 2023/02/05 15:03:51 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "philos.h"

static int	abort_init(t_philo *philos, t_shared *shared, int err_code)
{
	free(philos);
	free(shared->fork);
	free(shared->personal);
	return (err_code);
}

static int	init_mutexes(t_shared *shared, int n_philo)
{
	int	i;

	if (pthread_mutex_init(&shared->common, NULL) != 0)
		return (destroy_mutexes(shared, n_philo));
	i = 0;
	while (++i <= n_philo)
	{
		if (pthread_mutex_init(shared->fork + i, NULL) != 0 \
				|| pthread_mutex_init(shared->personal + i, NULL) != 0)
			return (destroy_mutexes(shared, n_philo));
	}
	return (CODE_OK);
}

static int	init_malloc(t_philo **philos, t_shared *shared, t_rules *rules)
{
	*philos = malloc(sizeof(t_philo) * (rules->n_philo + 1));
	shared->fork = malloc(sizeof(pthread_mutex_t) * (rules->n_philo + 1));
	shared->personal = malloc(sizeof(pthread_mutex_t) * (rules->n_philo + 1));
	if (!philos || !shared->fork || !shared->personal)
		return (abort_init(*philos, shared, CODE_ERROR_MALLOC));
	memset(*philos, 0, sizeof(t_philo) * (rules->n_philo + 1));
	memset(shared->fork, 0, sizeof(pthread_mutex_t) * (rules->n_philo + 1));
	memset(shared->personal, 0, sizeof(pthread_mutex_t) * (rules->n_philo + 1));
	return (CODE_OK);
}

int	init(t_philo **philos, t_shared *shared, t_rules *rules)
{
	int				i;

	if (init_malloc(philos, shared, rules) == CODE_ERROR_MALLOC)
		return (CODE_ERROR_MALLOC);
	shared->rules = rules;
	if (init_mutexes(shared, rules->n_philo) != CODE_OK)
		return (abort_init(*philos, shared, CODE_ERROR_GENERIC));
	i = 0;
	while (++i <= rules->n_philo)
	{
		(*philos)[i].id = i;
		(*philos)[i].shared = shared;
		if (i == rules->n_philo)
			(*philos)[i].lfork = shared->fork + 1;
		else
			(*philos)[i].lfork = shared->fork + i + 1;
		(*philos)[i].rfork = shared->fork + i;
	}
	return (CODE_OK);
}
