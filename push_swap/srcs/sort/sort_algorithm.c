/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:09:50 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/02 20:38:37 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data_structure.h"
#include "../../includes/sort.h"

int	calc_proper_idx(int idx, int st_size)
{
	int	ret;

	if (idx > st_size / 2)
		ret = (st_size - idx) * -1;
	else
		ret = idx;
	return (ret);
}

//This function must and will return while it's in the while loop
//If not, some error occur
//
//Just finding proper idx to insert target
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
		if (cur->data < target && target < cur->prev->data)
			return (calc_proper_idx(idx, set->st_b->size));
		cur = cur->next;
	}
	return (-4242);
}

//This function must and will return in while loop
//If not, there is some error occur
//
//Just finding proper idx to insert target
//There are the two case 1.sorted intervals, 2.unsorted intervals.
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
	return (-4242);
}

//If first value is bigger than the last one, then st_b is unsorted
int	calc_insertion_idx(t_info *set, int target)
{
	int		b_idx;

	if (get_front(set->st_b) > get_rear(set->st_b))
		b_idx = calc_idx_sorted(set, target);
	else
		b_idx = calc_idx_unsorted(set, target);
	return (b_idx);
}

//Minimum-operation count is cacluated with two values
//So, it would be better to pass the two value to calculation function
//
//a_idx means location of current node
//b_idx means location where current node should be inserted
//Consequently idx means the number of rotation-operations required
//
//idx has a positive or negative value. 
//if idx is positive then ra or rb will be chosen
//else rra or rrb will be chosen
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
