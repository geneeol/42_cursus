/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:45:05 by dahkang           #+#    #+#             */
/*   Updated: 2022/11/14 03:25:41 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>

typedef int t_bool;

#define FALSE 0
#define TRUE 1

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node		*front;
	t_node		*rear;
	size_t		size;
}	t_stack;

t_node	*ft_creat_node(int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->data = data;
	node->next = 0;
	node->prev = 0;
	return (node);
}

t_bool	push_front(t_stack *stk, int data)
{
	t_node	*new_node;

	new_node = ft_creat_node(data); 
	if (!new_node)
		return (FALSE);
	if (stk->size == 0)
	{
		stk->front = new_node;
		stk->rear = new_node;
	}
	else
	{
		new_node->next = stk->front;
		stk->front->prev = new_node;
		stk->front = new_node;
		(stk->size)++;
	}
	return (TRUE);
}

t_bool	push_rear(t_stack *stk, int data)
{
	t_node	*new_node;

	new_node = ft_creat_node(data); 
	if (!new_node)
		return (FALSE);
	if (stk->size == 0)
	{
		stk->rear = new_node;
		stk->front = new_node;
	}
	else
	{
		new_node->prev = stk->rear;
		stk->rear->next = new_node;
		stk->rear = new_node;
		(stk->size)++;
	}
	return (TRUE);
}

int	pop_front(t_stack *stk)
{
	t_node	*tmp;

	if (stk->size == 0)
		return (-1);
	tmp = stk->front->next;
	free(stk->front);
	if (tmp)
		tmp->prev = 0;
	stk->front = tmp;
	(stk->size)--;
	return (1);
}
