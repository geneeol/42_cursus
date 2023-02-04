/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 04:11:29 by dahkang           #+#    #+#             */
/*   Updated: 2023/02/05 06:03:42 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "philos.h"

static int	abort_init(t_philo *philos, t_args *args, int err_code)
{
	free(philos);
	free(args->fork);
	free(args->personal);
	return (err_code);
}

static int	init_mutexes(t_args *args, int n_philo)
{
	int	i;

	if (pthread_mutex_init(&args->common, NULL) != 0)
		return (destroy_mutexes(args, n_philo));
	i = 0;
	while (++i <= n_philo)
	{
		if (pthread_mutex_init(args->fork + i, NULL) != 0 \
				|| pthread_mutex_init(args->personal + i, NULL) != 0)
			return (destroy_mutexes(args, n_philo));
	}
	return (CODE_OK);
}

static int	init_malloc(t_philo **philos, t_args *args, t_rules *rules)
{
	*philos = malloc(sizeof(t_philo) * (rules->n_philo + 1));
	args->fork = malloc(sizeof(pthread_mutex_t) * (rules->n_philo + 1));
	args->personal = malloc(sizeof(pthread_mutex_t) * (rules->n_philo + 1));
	if (!philos || !args->fork || !args->personal)
		return (abort_init(*philos, args, CODE_ERROR_MALLOC));
	memset(*philos, 0, sizeof(t_philo) * (rules->n_philo + 1));
	memset(args->fork, 0, sizeof(pthread_mutex_t) * (rules->n_philo + 1));
	memset(args->personal, 0, sizeof(pthread_mutex_t) * (rules->n_philo + 1));
	return (CODE_OK);
}

int	init(t_philo **philos, t_args *args, t_rules *rules)
{
	int				i;

	if (init_malloc(philos, args, rules) == CODE_ERROR_MALLOC)
		return (CODE_ERROR_MALLOC);
	args->rules = rules;
	if (init_mutexes(args, rules->n_philo) != CODE_OK)
		return (abort_init(*philos, args, CODE_ERROR_GENERIC));
	i = 0;
	while (++i <= rules->n_philo)
	{
		(*philos)[i].id = i;
		(*philos)[i].args = args;
		if (i == rules->n_philo)
			(*philos)[i].lfork = args->fork + 1;
		else
			(*philos)[i].lfork = args->fork + i + 1;
		(*philos)[i].rfork = args->fork + i;
	}
	return (CODE_OK);
}
