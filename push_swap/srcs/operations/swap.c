/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:36:33 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/02 14:04:55 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data_structure.h"
#include "../../includes/operations.h"

t_bool	swap(t_stack *st)
{
	t_node	*head;
	int		tmp;

	if (st->size <= 1)
		return (FALSE);
	head = st->front;
	tmp = head->data;
	head->data = head->next->data;
	head->next->data = tmp;
	return (TRUE);
}

t_bool	sa(t_info *set)
{
	push_rear(set->op_queue, SA);
	return (swap(set->st_a));
}

t_bool	sb(t_info *set)
{
	push_rear(set->op_queue, SB);
	return (swap(set->st_b));
}

t_bool	ss(t_info *set)
{
	t_bool	res[2];

	push_rear(set->op_queue, SS);
	res[0] = swap(set->st_a);
	res[1] = swap(set->st_b);
	return (res[0] && res[1]);
}
