/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:24:53 by dahkang           #+#    #+#             */
/*   Updated: 2023/02/05 06:05:53 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "philos.h"

static int	atoi_if_valid(int *res, char *str, int mode)
{
	int	i;

	i = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		if (*res > INT_MAX / 10 \
				|| (*res == INT_MAX / 10 && str[i] > INT_MAX % 10))
			return (CODE_ERROR_GENERIC);
		*res *= 10;
		*res += str[i] - '0';
		i++;
	}
	if (i == 0 || str[i] != 0)
		return (CODE_ERROR_GENERIC);
	if (mode == TIME)
	{
		if (*res > INT_MAX / 1000)
			return (CODE_ERROR_GENERIC);
		*res *= 1000;
	}
	return (CODE_OK);
}

int	parse_input(t_rules *rules, int argc, char **argv)
{
	memset(rules, 0, sizeof(t_rules));
	if (atoi_if_valid(&(rules->n_philo), argv[1], ORIGIN) != CODE_OK \
		|| atoi_if_valid((int *)&(rules->time_die), argv[2], TIME) != CODE_OK \
		|| atoi_if_valid((int *)&(rules->time_eat), argv[3], TIME) != CODE_OK \
		|| atoi_if_valid((int *)&(rules->time_sleep), argv[4], TIME) != CODE_OK)
		return (CODE_ERROR_GENERIC);
	if (argc == 6)
	{
		if (atoi_if_valid(&(rules->n_must_eat), argv[5], ORIGIN) != CODE_OK)
			return (CODE_ERROR_GENERIC);
	}
	else
		rules->n_must_eat = -1;
	return (CODE_OK);
}
