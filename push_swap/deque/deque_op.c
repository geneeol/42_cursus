/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:06:55 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/01 11:13:43 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_bool	push_front(t_stack *st, int data)
{
	t_node	*new_node;

	new_node = ft_creat_node(data);
	if (!new_node)
		ft_err_exit(EXIT_FAILURE);
	if (st->size == 0)
	{
		st->front = new_node;
		st->rear = new_node;
	}
	else
	{
		new_node->next = st->front;
		st->front->prev = new_node;
		st->front = new_node;
	}
	(st->size)++;
	return (TRUE);
}

t_bool	push_rear(t_stack *st, int data)
{
	t_node	*new_node;

	new_node = ft_creat_node(data);
	if (!new_node)
		ft_err_exit(EXIT_FAILURE);
	if (st->size == 0)
	{
		st->rear = new_node;
		st->front = new_node;
	}
	else
	{
		new_node->prev = st->rear;
		st->rear->next = new_node;
		st->rear = new_node;
	}
	(st->size)++;
	return (TRUE);
}

t_bool	pop_front(t_stack *st)
{
	t_node	*tmp;

	if (st->size == 0)
		return (FALSE);
	tmp = st->front;
	st->front = st->front->next;
	if (!(st->front))
		st->rear = 0;
	else
		st->front->prev = 0;
	free(tmp);
	(st->size)--;
	return (TRUE);
}

t_bool	pop_rear(t_stack *st)
{
	t_node	*tmp;

	if (st->size == 0)
		return (FALSE);
	tmp = st->rear;
	st->rear = st->rear->prev;
	if (!(st->rear))
		st->front = 0;
	else
		st->rear->next = 0;
	free(tmp);
	(st->size)--;
	return (TRUE);
}
