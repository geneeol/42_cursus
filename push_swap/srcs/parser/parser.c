/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:51:51 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/01 11:45:51 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_info	*parser_quote(char **argv)
{
	t_info	*ret;
	char	**args;
	int		res;	
	int		i;

	args = ft_split(argv[1], ' ');
	if (!args)
		ft_err_exit(EXIT_FAILURE);
	ret = init_info();
	i = -1;
	while (args[++i])
	{
		if (atoi_is_valid(args[i], &res) && !is_duplicate(ret->st_a, res))
			push_rear(ret->st_a, res);
		else
			ft_err_exit(EXIT_FAILURE);
	}
	free_args(args);
	return (ret);
}

t_info	*parser_many_args(int argc, char **argv)
{
	t_info	*ret;
	int		i;
	int		res;

	ret = init_info();
	i = 0;
	while (++i < argc)
	{
		if (atoi_is_valid(argv[i], &res) && !is_duplicate(ret->st_a, res))
			push_rear(ret->st_a, res);
		else
			ft_err_exit(EXIT_FAILURE);
	}
	return (ret);
}

t_info	*input_parser(int argc, char **argv)
{
	t_info	*ret;

	if (argc < 2)
		ft_err_exit(EXIT_FAILURE);
	if (argc == 2)
		ret = parser_quote(argv);
	if (argc > 2)
		ret = parser_many_args(argc, argv);
	return (ret);
}
