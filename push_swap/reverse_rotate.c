/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:40:43 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/01 11:26:30 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

//1. 가독성을 위해 pop, push 연산 사용
//이 경우 malloc실패에 대한 별도의 분기처리가 필요함
//2. 새로운 동적할당 없이 기존 노드를 이용해서 재배열
//malloc실패애 대한 예외처리는 필요 없지만 코드가 지저분해짐

t_bool	reverse_rotate(t_stack *st)
{
	int		val;

	if (st->size <= 1)
		return (FALSE);
	val = st->rear->data;
	pop_rear(st);
	return (push_front(st, val));
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
	t_bool	res[2];

	push_rear(set->op_queue, RRR);
	res[0] = reverse_rotate(set->st_a);
	res[1] = reverse_rotate(set->st_b);
	return (res[0] && res[1]);
}
