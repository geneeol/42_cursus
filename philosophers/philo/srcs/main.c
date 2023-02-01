/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:55:09 by kkab              #+#    #+#             */
/*   Updated: 2023/02/02 04:16:31 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philos.h"
#include "structures.h"

int	monitor_if_done(t_philo *philos, t_args *args)
{
	int	i;

	while (TRUE)
	{
		i = 1
	}
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
		|| create_threads(philos, &args, &rules) != CODE_OK)
	{
		printf("Critical: Failed to start simulation\n");
		return (1);
	}
	monitor_if_done(philos, &args);
	return (0);
}