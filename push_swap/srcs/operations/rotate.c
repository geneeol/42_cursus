/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:42:30 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/02 14:04:42 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data_structure.h"
#include "../../includes/operations.h"

t_bool	rotate(t_stack *st)
{
	int		val;

	if (st->size <= 1)
		return (FALSE);
	val = st->front->data;
	pop_front(st);
	return (push_rear(st, val));
}

t_bool	ra(t_info *set)
{
	push_rear(set->op_queue, RA);
	return (rotate(set->st_a));
}

t_bool	rb(t_info *set)
{
	push_rear(set->op_queue, RB);
	return (rotate(set->st_b));
}

t_bool	rr(t_info *set)
{
	t_bool	res[2];

	push_rear(set->op_queue, RR);
	res[0] = rotate(set->st_a);
	res[1] = rotate(set->st_b);
	return (res[0] && res[1]);
}
