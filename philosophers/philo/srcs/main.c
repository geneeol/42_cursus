/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:55:09 by kkab              #+#    #+#             */
/*   Updated: 2023/02/01 20:05:34 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "philos.h"

/*
void	odd_routine(t_philo *philo)
{
	while (!is_done(philo))
	{
		eating();
		thinking();
		sleeping();
		//필요시 잠깐 재우기 usleep()
	}
}

// TODO: 몇초 자야되지..?
void	even_routine(t_philo *philo)
{
	usleep(800);
	while (!is_done(philo))
	{
		eating();
		thinking();
		sleeping();
		//필요시 잠깐 재우기 usleep()
	}
}
*/

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)philo;
	pthread_mutex_lock(&philo->args->mt_lock);
	while (philo->args->is_start == 0)
		;
	pthread_mutex_unlock(&philo->args->mt_lock);
	printf("%dth philo is created\n", philo->id);
	/*
	if ((philo->id & 1) == 1)
		odd_routine(philo);
	else
		even_routine(philo);
	*/
	return (NULL);
}

static int	abort_create_threads(t_philo *philos, int err_code)
{
	int	i;

	i = 0;
	while (++i <= philos->args->rules->n_philo)
		pthread_detach((philos + i)->thread);
	return (err_code);
}

// TODO: args 초기화 안해도 값이 0인지 확인. (static이라 0일 것임)
static int	create_threads(t_philo *philos)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philos->args->mt_lock);
	while (++i <= philos->args->rules->n_philo)
	{
		if (pthread_create(&(philos + i)->thread, NULL, routine, philos + i))
			return (abort_create_threads(philos, CODE_ERROR_GENERIC));
		sleep(1);
	}
	philos->args->is_start = 1;
	pthread_mutex_unlock(&philos->args->mt_lock);
	return (CODE_OK);
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
		|| create_threads(philos) != CODE_OK)
	{
		printf("Critical: Failed to start simulation\n");
		return (1);
	}
	//monitoring_until_done(&args);
	return (0);
}
