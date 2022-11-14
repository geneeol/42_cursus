/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:45:05 by dahkang           #+#    #+#             */
/*   Updated: 2022/11/14 14:18:39 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include <stdlib.h>
#include <stdio.h>


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
	}
	(stk->size)++;
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
	}
	(stk->size)++;
	return (TRUE);
}

int	pop_front(t_stack *stk)
{
	t_node	*tmp;

	if (stk->size == 0)
		return (-1);
	tmp = stk->front;
	stk->front = stk->front->next;
	if (!(stk->front))
		stk->rear = 0;
	else
		stk->front->prev = 0;
	free(tmp);
	(stk->size)--;
	return (1);
}

int	pop_rear(t_stack *stk)
{
	t_node	*tmp;

	if (stk->size == 0)
		return (-1);
	tmp = stk->rear;
	stk->rear = stk->rear->prev;
	if (!(stk->rear))
		stk->front = 0;
	else
		stk->rear->next = 0;
	free(tmp);
	(stk->size)--;
	return (1);
}

//if stk is an empty stack what happend?
//I can't tell if ret=-1 is real value.
//because it can be also from the err value
//so this function should be called when stack isn't empty
int	get_front(t_stack *stk)
{
	return (stk->front->data);
}

int	get_rear(t_stack *stk)
{
	return (stk->rear->data);
}

void	stk_clear(t_stack *stk)
{
	t_node	*curr;
	t_node	*tmp;

	curr = stk->front;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	stk->size = 0;
}

t_stack	*init_stack()
{
	t_stack	*ret;

	ret = (t_stack *)malloc(sizeof(t_stack));
	ret->front = 0;
	ret->rear = 0;
	ret->size = 0;
	return (ret);
}
