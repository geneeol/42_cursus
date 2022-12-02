/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:27:40 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/02 22:38:42 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data_structure.h"
#include "../../includes/operations.h"
#include "../../includes/sort.h"

static void	align_b(t_info *set)
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

//elments of st_a will be inserted between elements of st_b
//It's simple,
//just compare rear of st_a with front of st_b and st_a
static void	sort_b_to_a(t_info *set)
{
	const int	a_min = get_front(set->st_a);
	const int	b_max = get_front(set->st_b);

	while (get_front(set->st_b) < get_rear(set->st_a)
		&& a_min < b_max)
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
