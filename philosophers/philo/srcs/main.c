/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:55:09 by kkab              #+#    #+#             */
/*   Updated: 2023/02/07 15:09:32 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "philos.h"

static t_bool	check_if_done(t_philo *philos, t_shared *shared)
{
	int		i;
	t_bool	eat_enough;

	i = 0;
	eat_enough = TRUE;
	while (++i <= shared->rules->n_philo)
	{
		pthread_mutex_lock(shared->personal + i);
		if (get_elapsed_time(philos[i].last_eat_time) > shared->rules->time_die)
		{
			print_die_and_mark_done("died", philos + i);
			pthread_mutex_unlock(shared->personal + i);
			return (TRUE);
		}
		if (shared->rules->n_must_eat == OPTION_OFF \
				|| philos[i].eat_cnt < shared->rules->n_must_eat)
			eat_enough = FALSE;
		pthread_mutex_unlock(shared->personal + i);
	}
	return (eat_enough);
}

static void	monitoring(t_philo *philos, t_shared *shared)
{
	while (TRUE)
	{
		if (check_if_done(philos, shared) == TRUE)
			break ;
		usleep(7000);
	}
	pthread_mutex_lock(&shared->common);
	shared->all_done = TRUE;
	pthread_mutex_unlock(&shared->common);
}

static void	retrieve_resources(t_philo *philos, \
								t_shared *shared, \
								t_rules *rules)
{
	int	i;

	i = 0;
	while (++i <= rules->n_philo)
		pthread_join((philos + i)->tid, NULL);
	destroy_mutexes(shared, rules->n_philo);
}

int	main(int argc, char **argv)
{
	static t_shared	shared;
	static t_rules	rules;
	t_philo			*philos;

	if (parse_input(&rules, argc, argv) != CODE_OK)
	{
		printf(USAGE_MSG);
		return (1);
	}
	if (rules.n_must_eat == 0)
		return (0);
	if (init(&philos, &shared, &rules) != CODE_OK
		|| create_threads(philos, &shared) != CODE_OK)
	{
		printf(CRITICAL_ERR_MSG);
		return (1);
	}
	monitoring(philos, &shared);
	retrieve_resources(philos, &shared, &rules);
	return (0);
}
