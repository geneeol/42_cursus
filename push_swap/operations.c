/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:40:43 by dahkang           #+#    #+#             */
/*   Updated: 2022/11/29 19:37:13 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

//1. 가독성을 위해 pop, push 연산 사용
//이 경우 malloc실패에 대한 별도의 분기처리가 필요함
//2. 새로운 동적할당 없이 기존 노드를 이용해서 재배열
//malloc실패애 대한 예외처리는 필요 없지만 코드가 지저분해짐
t_bool	swap(t_stack *stk)
{
	t_node	*head;
	int		tmp;

	if (stk->size <= 1)
		return (FALSE);
	head = stk->front;
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
	int	res[2];

	push_rear(set->op_queue, SS);
	res[0] = swap(set->st_a);
	res[1] = swap(set->st_b);
	return (res[0] && res[1]);
}

t_bool	push(t_stack *stk1, t_stack *stk2)
{
	if (stk2->size == 0)
		return (FALSE);
	push_front(stk1, stk2->front->data);
	pop_front(stk2);
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

t_bool	rotate(t_stack *stk)
{
	int		val;

	if (stk->size <= 1)
		return (FALSE);
	val = stk->front->data;
	pop_front(stk);
	return (push_rear(stk, val));
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
	int	res[2];

	push_rear(set->op_queue, RR);
	res[0] = rotate(set->st_a);
	res[1] = rotate(set->st_b);
	return (res[0] && res[1]);
}

t_bool	reverse_rotate(t_stack *stk)
{
	int		val;

	if (stk->size <= 1)
		return (FALSE);
	val = stk->rear->data;
	pop_rear(stk);
	return (push_front(stk, val));
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
	int	res[2];

	push_rear(set->op_queue, RRR);
	res[0] = reverse_rotate(set->st_a);
	res[1] = reverse_rotate(set->st_b);
	return (res[0] && res[1]);
}
