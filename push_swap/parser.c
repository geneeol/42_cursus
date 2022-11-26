/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:51:51 by dahkang           #+#    #+#             */
/*   Updated: 2022/11/26 19:25:32 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

#include <stdio.h>

static int	is_space(char ch)
{
	if (ch == '\t' || ch == '\n' || ch == '\v'
		|| ch == '\f' || ch == '\r' || ch == ' ')
		return (1);
	else
		return (0);
}

//libft
int	ft_isdigit(int ch)
{
	if ('0' <= ch && ch <= '9')
		return (1);
	else
		return (0);
}

t_bool	atoi_is_valid(char const *str, int *res)
{
	int			sign;
	long long	ret;

	sign = 1;
	ret = 0;
	*res = 0;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*(str++) == '-')
			sign *= -1;
	while (ft_isdigit(*str))
	{
		ret = ret * 10 + sign * (*(str++) - '0');
		if (ret > INT_MAX || ret < INT_MIN)
			return (FALSE);
	}
	*res = ret;
	return (*str == 0);
}

t_bool	is_duplicate(t_stack *stk, int res)
{
	t_node	*curr;

	curr = stk->front;
	while (curr)
	{
		if (curr->data == res)
			return (TRUE);
		curr = curr->next;
	}
	return (FALSE);
}

void	free_args(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
		free(args[i]);
	free(args);
}

//argc 사용을 안함...
t_info	*parser_quote(int argc, char **argv)
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
		ret = parser_quote(argc, argv); 
	if (argc > 2)
		ret = parser_many_args(argc, argv);
	return (ret);
}
