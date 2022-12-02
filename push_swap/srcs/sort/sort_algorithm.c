/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:09:50 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/01 19:30:52 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static int	calc_proper_idx(int idx, int st_size)
{
	int	ret;

	if (idx > st_size / 2)
		ret = (st_size - idx) * -1;
	else
		ret = idx;
	return (ret);
}

//고쳐야 함
static int	calc_idx_sorted(t_info *set, int target)
{
	t_node	*cur;
	int		idx;

	idx = 0;
	if (target > get_front(set->st_b) || target < get_rear(set->st_b))
		return (idx);
	cur = set->st_b->front->next;
	while (++idx < set->st_b->size)
	{
		// 이렇게 하면 안댐...
		if (cur->data < target && target < cur->prev->data)
			return (calc_proper_idx(idx, set->st_b->size));
		cur = cur->next;
	}
	// 이걸 넣어야 하나?
	return (-100000);
}

//고쳐야 함
static int	calc_idx_unsorted(t_info *set, int target)
{
	t_node	*cur;
	int		idx;

	idx = 0;
	if (get_front(set->st_b) < target && target < get_rear(set->st_b))
		return (idx);
	cur = set->st_b->front->next;
	while (++idx < set->st_b->size)
	{
		if (cur->prev->data > cur->data)
		{
			if (cur->data < target && target < cur->prev->data)
				return (calc_proper_idx(idx, set->st_b->size));
		}
		else
		{
			if (target < cur->prev->data || target > cur->data)
				return (calc_proper_idx(idx, set->st_b->size));
		}
		cur = cur->next;
	}
	//이거 넣어야 하나?
	return (-100000);
}

static int	calc_insertion_idx(t_info *set, int target)
{
	int		b_idx;

	//0번 인덱스는 맨위값과 맨 아래값을 비교해야함
	//나머지 인덱스는 현재값과 그 이전값.
	//만약 이전값이 현재값보다 크다면 그 경우를 예외처리 해주어야함
	//
	if (get_front(set->st_b) > get_rear(set->st_b))
		b_idx = calc_idx_sorted(set, target);
	else
		b_idx = calc_idx_unsorted(set, target);
	return (b_idx);
}

//최소 연산은 스택a, 스택b 두가지에 해당하는 변수가 필요하므로 인자두개를 포인터를 넘겨주는게 나음
void	calc_min_operations(int *a_op, int *b_op, t_info *set)
{
	t_node	*cur;
	int		idx;
	int		a_idx;
	int		b_idx;

	cur = set->st_a->front;
	idx = 0;
	while (idx < set->st_a->size)
	{
		//리턴한 인덱스값의 윗부분에 a원소를 삽입한다고 하자.
		//결국 리턴한 인덱스 값이 rb 또는 rrb 연산 횟수가 된다.
		b_idx = calc_insertion_idx(set, cur->data);
		a_idx = calc_proper_idx(idx, set->st_a->size);
		if (idx == 0
			|| (calc_total_op(a_idx, b_idx)) < calc_total_op(*a_op, *b_op))
		{
			*a_op = a_idx;
			*b_op = b_idx;
		}
		idx++;
		cur = cur->next;
	}
}
