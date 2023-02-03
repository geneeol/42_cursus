/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:55:09 by kkab              #+#    #+#             */
/*   Updated: 2023/02/03 15:47:38 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philos.h"
#include "structures.h"

// TODO:
// 1. info_lock 하나로 메시지 출력, last_eat_time, all_done 관리 (엄청 느릴듯)
// 2. last_eat_time만큼 뮤텍스 생성, all_done은 별도 뮤텍스로 관리

static t_bool	set_all_done_if_true(t_args *args, t_bool bool)
{
	pthread_mutex_lock(&args->common);
	if (bool == TRUE)
		args->all_done = TRUE;
	pthread_mutex_unlock(&args->common);
	return (bool);
}

static t_bool	check_if_done(t_philo *philos, t_args *args)
{
	int		i;
	t_bool	eat_enough;

	i = 0;
	eat_enough = TRUE;
	while (++i <= args->rules->n_philo)
	{
		pthread_mutex_lock(args->personal + i);
		if (get_elapsed_time(philos[i].last_eat_time) \
			> args->rules->time_die)
		{
			pthread_mutex_unlock(args->personal + i);
			print_msg("died", i, args);
			return (set_all_done_if_true(args, TRUE));
		}
		if (args->rules->n_must_eat != -1)
		{
			if (philos[i].eat_cnt < args->rules->n_must_eat)
				eat_enough = FALSE;
		}
		else
			eat_enough = FALSE;
		pthread_mutex_unlock(args->personal + i);
	}
	return (set_all_done_if_true(args, eat_enough));
}

static void	monitoring(t_philo *philos, t_args *args)
{

	while (TRUE)
	{
		if (check_if_done(philos, args) == TRUE)
			return ;
		usleep(300);
	}
}

static void	join_all_thread(t_philo *philos, t_rules *rules)
{
	int	i;

	i = 0;
	while (++i <= rules->n_philo)
		pthread_detach(philos->tid);
		//pthread_join(philos->tid, NULL);
}

// TODO: 에러메시지 + 리턴코드 합친 함수 만들지 고민
int	main(int argc, char **argv)
{
	static t_args	args;
	t_philo			*philos;
	t_rules			rules;

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
	join_all_thread(philos, &rules);
	return (0);
}