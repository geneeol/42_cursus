/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:08:15 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/01 17:09:02 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	free_deque(t_stack *st)
{
	t_node	*cur;
	t_node	*tmp;

	cur = st->front;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	free(st);
}

void	free_info(t_info *set)
{
	free_deque(set->st_a);
	free_deque(set->st_b);
	free_deque(set->op_queue);
	free(set);
}
