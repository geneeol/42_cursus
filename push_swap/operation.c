/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:40:43 by dahkang           #+#    #+#             */
/*   Updated: 2022/11/18 15:03:59 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "deque.c"

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

t_bool	swap_a(t_stack *stk_a)
{
	return (swap(stk_a));
}

t_bool	swap_b(t_stack *stk_b)
{
	return (swap(stk_b));
}

t_bool	push(t_stack *stk1, t_stack *stk2)
{
	if (stk2->size == 0)
		return (FALSE);
	push_front(stk1, stk2->front->data);
	pop_front(stk2);
	return (TRUE);
}

t_bool	push_a(t_stack *stk_a, t_stack *stk_b)
{
	return (push(stk_a, stk_b));
}

t_bool	push_b(t_stack *stk_b, t_stack *stk_a)
{
	return (push(stk_b, stk_a));
}

t_bool	rotate(t_stack *stk)
{
	t_node	*head;
	t_node	*tail;
	int		tmp;

	if (stk->size <= 1)
		return (FALSE);
	head = stk->front;
	tail = stk->rear;
	tmp = stk->front->data;
	head->data = tail->data;
	tail->data = tmp;
	return (TRUE);
}
