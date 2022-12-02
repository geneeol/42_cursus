/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:09:21 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/02 15:00:52 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data_structure.h"
#include "../../includes/operations.h"
#include "../../includes/sort.h"

static void	sort_a_2(t_info *set)
{
	t_node	*cur;

	cur = set->st_a->front;
	if (cur->data > cur->next->data)
		sa(set);
}

void	sort_a_3(t_info *set)
{
	const int	top = set->st_a->front->data;
	const int	mid = set->st_a->front->next->data;
	const int	bot = set->st_a->front->next->next->data;

	if (top < mid && mid < bot)
		return ;
	else if (top < bot && bot < mid)
	{
		rra(set);
		sa(set);
	}
	else if (mid < top && top < bot)
		sa(set);
	else if (bot < top && top < mid)
		rra(set);
	else if (mid < bot && bot < top)
		ra(set);
	else if (bot < mid && mid < top)
	{
		sa(set);
		rra(set);
	}
}

//idx means the which number it is in ascending order
static int	get_target_idx(int target, t_stack *st)
{
	int		idx;
	t_node	*cur;

	idx = 0;
	cur = st->front;
	while (cur)
	{
		if (target < cur->data)
			return (idx);
		cur = cur->next;
		idx++;
	}
	return (idx);
}

//left value is placed in the st_b
//idx = 0 means left_value is the lowest value in ascending order
//idx = 3 means left_value is the highest value in ascending order
static void	insert_left_to_a(t_info *set)
{
	int	left_idx;

	left_idx = get_target_idx(get_front(set->st_b), set->st_a);
	if (left_idx == 0)
		pa(set);
	else if (left_idx == 1)
	{
		pa(set);
		sa(set);
	}
	else if (left_idx == 2)
	{
		ra(set);
		pa(set);
		sa(set);
		rra(set);
	}
	else if (left_idx == 3)
	{
		pa(set);
		ra(set);
	}
}

//If st_size = 4,
//then sort stack by sort_a_3 && insert_left_to_a
void	sort_small(t_info *set)
{
	if (set->st_a->size == 2)
		sort_a_2(set);
	else if (set->st_a->size == 3)
		sort_a_3(set);
	else if (set->st_a->size == 4)
	{
		pb(set);
		sort_a_3(set);
		insert_left_to_a(set);
	}
}
