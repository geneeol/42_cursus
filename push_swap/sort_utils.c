/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:36:20 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/01 16:31:45 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

//그냥 오름차순 정렬만 검사할 것
int	is_asc_sorted(t_stack *st)
{
	t_node	*cur;
	int		status;

	cur = st->front;
	status = 0;
	while (cur->next)
	{
		if (cur->data < cur->next->data)
		{
			if (status == 2)
				return (0);
			status = 1;
		}
		else
		{
			if (status == 1)
				return (0);
			status = 2;
		}
		cur = cur->next;
	}
	return (status);
}

int	abs(int n)
{
	if (n > 0)
		return (n);
	else
		return (-n);
}

int	abs_max(int a, int b)
{
	if (abs(a) > abs(b))
		return (abs(a));
	else
		return (abs(b));
	/*
	if (a < 0 && b < 0)
	{
		if (a > b)
			return (-b);
		else
			return (-a);
	}
	else
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
	*/
}

int	calc_total_op(int a, int b)
{
	/*
	if (a > 0 && b > 0)
		return (abs_max(a, b));
	else if (a < 0 && b < 0)
		return (abs_max(a, b));
	*/
	if (a * b > 0)
		return (abs_max(a, b));
	else
		return (abs(a - b));
}

