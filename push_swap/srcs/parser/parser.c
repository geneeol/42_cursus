/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:51:51 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/02 22:31:30 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/libft.h"
#include "../../includes/data_structure.h"
#include "../../includes/parser.h"
#include <stdlib.h>

static void	push_args(char **args, t_info *set)
{
	int	res;
	int	i;

	i = 0;
	while (args[i])
	{
		if (atoi_is_valid(args[i], &res) && !is_duplicate(set->st_a, res))
			push_rear(set->st_a, res);
		else
			ft_err_exit(0, EXIT_FAILURE);
		i++;
	}
	free_args(args);
}

t_info	*input_parser(int argc, char **argv)
{
	t_info	*ret;
	char	**args;
	int		i;

	ret = init_info();
	i = 0;
	while (++i < argc)
	{
		args = ft_split((argv[i]), ' ');
		if (!args)
			ft_err_exit(0, EXIT_FAILURE);
		push_args(args, ret);
	}
	return (ret);
}
