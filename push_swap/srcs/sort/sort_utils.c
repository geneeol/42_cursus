/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:36:20 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/02 15:10:07 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data_structure.h"
#include "../../includes/operations.h"
#include "../../includes/sort.h"

t_bool	is_asc_sorted(t_stack *st)
{
	t_node	*cur;

	cur = st->front;
	while (cur->next)
	{
		if (cur->data > cur->next->data)
			return (FALSE);
		cur = cur->next;
	}
	return (TRUE);
}

static int	ft_abs(int n)
{
	if (n > 0)
		return (n);
	else
		return (-n);
}

static int	abs_max(int a, int b)
{
	if (ft_abs(a) > ft_abs(b))
		return (ft_abs(a));
	else
		return (ft_abs(b));
}

int	calc_total_op(int a, int b)
{
	if (a * b > 0)
		return (abs_max(a, b));
	else
		return (ft_abs(a - b));
}
