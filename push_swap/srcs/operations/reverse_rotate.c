/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:40:43 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/02 14:04:23 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data_structure.h"
#include "../../includes/operations.h"

t_bool	reverse_rotate(t_stack *st)
{
	int		val;

	if (st->size <= 1)
		return (FALSE);
	val = st->rear->data;
	pop_rear(st);
	return (push_front(st, val));
}

t_bool	rra(t_info *set)
{
	push_rear(set->op_queue, RRA);
	return (reverse_rotate(set->st_a));
}

t_bool	rrb(t_info *set)
{
	push_rear(set->op_queue, RRB);
	return (reverse_rotate(set->st_b));
}

t_bool	rrr(t_info *set)
{
	t_bool	res[2];

	push_rear(set->op_queue, RRR);
	res[0] = reverse_rotate(set->st_a);
	res[1] = reverse_rotate(set->st_b);
	return (res[0] && res[1]);
}
