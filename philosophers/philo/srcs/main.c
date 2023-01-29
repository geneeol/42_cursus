/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:55:09 by kkab              #+#    #+#             */
/*   Updated: 2023/01/30 03:28:42 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "philos.h"

void	odd_routine(t_philo *philo)
{
	while (!philo->args->done)
	{
		eat();
		think();
		sleep();
	}
}

void	even_routine(t_philo *philo)
{
	while (!philo->args->done)
	{
		eat();
		think();
		sleep();
	}
}

// args를 여러 쓰레드가 동시에 읽는 경우 발생 가능. 데이터레이스인지 아닌지는 모르겠음
void	*routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)philo;
	while (philo->args->start_flag == 0)
		;
	if ((philo->id & 1) == 1)
		odd_routine(philo);
	else
		even_routine(philo);
	return (NULL);
}

// 이 분기에서 바로 main에서 리턴한다면, 굳이 동적할당 해제하지 않아도 될 것 같은데
int	abort_while_creating(pthread_t *philo, int n, int err)
{
	int	i;

	i = -1;
	while (++i < n - 1)
		pthread_detach(philo[i]);
	return (err);
}

// 각 철학자 아이디 1~n까지, 누가 죽었는지 확인해야함
// 출력도 별도로 처리애햐함
static int	set_dining(t_input *input)
{
	static t_args	args;	
	t_philo			*philo;
	int				i;

	philo = (t_philo *)malloc(sizeof(t_philo) * (input->n_philo + 1));
	if (!philo || init_args(&args) == CODE_ERROR_MALLOC)
		return (free_with_fail(philo, &args));
	i = 0;
	while (++i <= input->n_philo)
	{
		philo[i].id = i;
		philo[i].args = &args;
		philo[i].left = (i + 1) % input->n_philo;
		philo[i].right = i;
		if (pthread_create((philo + i)->thread, NULL, routine, philo + i))
			return (abort_while_creating(philo, i, CODE_ERROR_GENERIC));
	}
	args.start_flag = 1;
	i = 0;
	while (++i < input->n_philo)
		pthread_join((philo + i)->thread, NULL);
	return (CODE_OK);
}

int	main(int argc, char **argv)
{
	t_input	input;
	int		stat;

	if (!(argc == 5 || argc == 6))
	{
		printf("Invalid number of arguments\n");
		return (1);
	}
	stat = parse_input(&input, argc, argv);
	if (stat != CODE_OK)
	{
		printf("Invalid argument\n");
		return (1);
	}
	set_dining(&input);
	return (0);
}
