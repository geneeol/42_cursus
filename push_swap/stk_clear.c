/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:45:05 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/01 11:25:32 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>


//얘 어케할지 고민
void	stack_clear(t_stack *st)
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
	st->size = 0;
}
