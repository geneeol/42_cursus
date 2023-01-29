/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:24:53 by dahkang           #+#    #+#             */
/*   Updated: 2023/01/29 18:28:18 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "philos.h"

#define TIME 0
#define ORIGIN 1

// TODO: overflow나서 고려할 것
static int	atoi_if_valid(int *res, char *str, int mode)
{
	int	i;

	i = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		if (*res > 214748364 || (*res == 214748364 && str[i] > '7'))
			return (CODE_ERROR_GENERIC);
		*res *= 10;
		*res += str[i] - '0';
		i++;
	}
	if (i == 0 || str[i] != 0)
		return (CODE_ERROR_GENERIC);
	if (mode == TIME)
	{
		if (*res > 2147483)
			return (CODE_ERROR_GENERIC);
		*res *= 1000;
	}
	return (CODE_OK);
}

int	parse_input(t_input *input, int argc, char **argv)
{
	int	stat;

	stat = 0;
	memset(input, 0, sizeof(t_input));
	if (atoi_if_valid(&(input->n_philo), argv[1], ORIGIN) \
		|| atoi_if_valid(&(input->time_die), argv[2], TIME) \
		|| atoi_if_valid(&(input->time_eat), argv[3], TIME) \
		|| atoi_if_valid(&(input->time_sleep), argv[4], TIME))
		return (CODE_ERROR_GENERIC);
	if (argc == 6)
	{
		if (!atoi_if_valid(&(input->n_must_eat), argv[5], ORIGIN))
			return (CODE_ERROR_GENERIC);
		input->option = 1;
	}
	return (CODE_OK);
}