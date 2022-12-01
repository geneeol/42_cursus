/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:27:40 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/01 16:14:31 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"


// b가 전부 정렬되어있느냐, 중간에 역순인 부분이 있느냐에 따라 또 나뉨
// 몇번째 인덱스에 넣을지 찾는게 생각보다 까다로움.........

void	align_b(t_info *set)
{
	t_node	*cur;
	int		idx;

	if (get_front(set->st_b) > get_rear(set->st_b))
		return ;
	cur = set->st_b->front;
	idx = 1;
	while (cur)
	{
		if (cur->data < cur->next->data)
			break ;
		idx++;
		cur = cur->next;
	}
	idx = calc_proper_idx(idx, set->st_b->size);
	exec_rotation_b(idx, set);
}

//여기서 가독성 에바

void	sort_b_to_a(t_info *set)
{
	while (get_front(set->st_b) < get_rear(set->st_a))
		rra(set);
	while (set->st_b->size)
	{
		pa(set);
		while (set->st_b->size && get_front(set->st_b) < get_rear(set->st_a)
			&& get_rear(set->st_a) < get_front(set->st_a))
			rra(set);
	}
	while (get_front(set->st_a) > get_rear(set->st_a))
		rra(set);
}

//a에서 b로 넘긴 이후 b에서 정렬하는 것이 필요한가?
//만약 연산횟수가 똑같다면 rb 혹은 rrb로 정렬해두는 것이 좋을듯
//
//sort_a_3에 대한 분류
void	sort_big(t_info *set)
{
	int		a_op;
	int		b_op;

	pb(set);
	pb(set);
	while (set->st_a->size > 3)
	{
		a_op = 0;
		b_op = 0;
		calc_min_operations(&a_op, &b_op, set);
		exec_rotation_same(&a_op, &b_op, set);
		exec_rotation_a(a_op, set);
		exec_rotation_b(b_op, set);
		pb(set);
	}
	sort_a_3(set);
	align_b(set);
	sort_b_to_a(set);
}
