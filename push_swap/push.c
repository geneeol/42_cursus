/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:40:20 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/01 10:44:17 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_bool	push(t_stack *st1, t_stack *st2)
{
	if (st2->size == 0)
		return (FALSE);
	push_front(st1, st2->front->data);
	pop_front(st2);
	return (TRUE);
}

t_bool	pa(t_info *set)
{
	push_rear(set->op_queue, PA);
	return (push(set->st_a, set->st_b));
}

t_bool	pb(t_info *set)
{
	push_rear(set->op_queue, PB);
	return (push(set->st_b, set->st_a));
}
