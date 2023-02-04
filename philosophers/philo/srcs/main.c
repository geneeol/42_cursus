/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:55:09 by kkab              #+#    #+#             */
/*   Updated: 2023/02/05 06:05:43 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "philos.h"

static t_bool	check_if_done(t_philo *philos, t_args *args)
{
	int		i;
	t_bool	eat_enough;

	i = 0;
	eat_enough = TRUE;
	while (++i <= args->rules->n_philo)
	{
		pthread_mutex_lock(args->personal + i);
		if (get_elapsed_time(philos[i].last_eat_time) > args->rules->time_die)
		{
			print_die_and_mark_done("died", i, args);
			pthread_mutex_unlock(args->personal + i);
			return (TRUE);
		}
		if (args->rules->n_must_eat == OPTION_OFF \
				|| philos[i].eat_cnt < args->rules->n_must_eat)
			eat_enough = FALSE;
		pthread_mutex_unlock(args->personal + i);
	}
	return (eat_enough);
}

static void	monitoring(t_philo *philos, t_args *args)
{
	while (TRUE)
	{
		if (check_if_done(philos, args) == TRUE)
			break ;
		usleep(7000);
	}
	pthread_mutex_lock(&args->common);
	args->all_done = TRUE;
	pthread_mutex_unlock(&args->common);
}

static void	retrieve_resources(t_philo *philos, t_args *args, t_rules *rules)
{
	int	i;

	i = 0;
	while (++i <= rules->n_philo)
		pthread_join(philos->tid, NULL);
	destroy_mutexes(args, rules->n_philo);
}

int	main(int argc, char **argv)
{
	static t_args	args;
	static t_rules	rules;
	t_philo			*philos;

	if (!(argc == 5 || argc == 6))
	{
		printf("Invalid: The number of arguments should be 5 or 6\n");
		return (1);
	}
	if (parse_input(&rules, argc, argv) != CODE_OK)
	{
		printf("Invalid: At least one argument is incorrect\n");
		return (1);
	}
	if (init(&philos, &args, &rules) != CODE_OK
		|| create_threads(philos, &args) != CODE_OK)
	{
		printf("Critical: Failed to start simulation\n");
		return (1);
	}
	monitoring(philos, &args);
	retrieve_resources(philos, &args, &rules);
	return (0);
}
