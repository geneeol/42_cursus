/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:37:21 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/02 19:53:05 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/libft.h"
#include "../../includes/parser.h"

static int	is_space(char ch)
{
	if (ch == '\t' || ch == '\n' || ch == '\v'
		|| ch == '\f' || ch == '\r' || ch == ' ')
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
