/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:27:40 by dahkang           #+#    #+#             */
/*   Updated: 2022/11/28 21:03:22 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "operations.c"

int	abs_diff(int a, int b)
{
	int	diff;

	diff = a - b;
	if (diff < 0)
		return (-diff);
	else
		return (diff);
}

int	insert_to_b_in_order(t_info *set, int target)
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
			if (cur->data < target && target < cur->prev->data)
				return (idx * (2 * (idx >= set->st_b->size / 2) - 1));
		cur = cur->next;
	}
	// 이걸 넣어야 하나?
	return (-5000);
}

int	insert_to_b_out_order(t_info *set, int target)
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
				return (idx * (2 * (idx >= set->st_b->size / 2) - 1));
		}
		else
			if (target < cur->prev->data || target > cur->data)
				return (idx * (2 * (idx >= set->st_b->size / 2) - 1));
	}
	//이거 넣어야 하나?
	return (-5000);
}

// b가 전부 정렬되어있느냐, 중간에 역순인 부분이 있느냐에 따라 또 나뉨
// 몇번째 인덱스에 넣을지 찾는게 생각보다 까다로움.........
int	insert_to_b_loc(t_info *set, int target)
{
	t_node	*cur;
	int		idx;

	cur = set->st_b->front;
	idx = 0;
	//0번 인덱스는 맨위값과 맨 아래값을 비교해야함
	//나머지 인덱스는 현재값과 그 이전값.
	//만약 이전값이 현재값보다 크다면 그 경우를 예외처리 해주어야함
	//

	if (get_front(set->st_b) > get_rear(set->st_b))
		idx = insert_to_b_in_order(set, target);
	else
		idx = insert_to_b_out_order(set, target);
	return (idx);
}

//함수명 바꾸는게 좋을듯??

//최소 연산은 스택a, 스택b 두가지에 해당하는 변수가 필요하므로 인자두개를 포인터를 넘겨주는게 나음
void	get_min_operations(int *a_op, int *b_op, t_info *set)
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
		b_idx = insert_to_b_loc(set, cur->data);
		//if (b_idx >= set->st_b->size / 2)
		//	b_idx = (set->st_b->size - b_idx - 1) * -1;
		if (idx > set->st_a->size / 2)
			a_idx = (set->st_a->size - idx) * -1;
		else
			a_idx = idx;
		if (idx == 0 || abs_diff(a_idx, b_idx) < abs_diff(*a_op, *b_op))
		{
			*a_op = a_idx;
			*b_op = b_idx;
		}
		idx++;
		cur = cur->next;
	}
}

//is_sorted 만들어야 하나?
//
//
//
void	sort_a_2(t_info *set)	
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

void	exec_same_rotation(int *a_op, int *b_op, t_info *set)
{
	while (*a_op && *b_op && (*a_op > 0 && *b_op > 0))
	{
		rr(set);
		(*a_op)--;
		(*b_op)--;
	}
	while (*a_op && *b_op && (*a_op < 0 && *b_op < 0))
	{
		rrr(set);
		(*a_op)++;
		(*b_op)++;
	}
}

void	ft_rotate_a(int a_op, t_info *set)
{
	while (a_op)
	{
		if (a_op > 0)
		{
			ra(set);
			a_op--;
		}
		else
		{
			rra(set);
			a_op++;
		
		}
	}
}

void	ft_rotate_b(int b_op, t_info *set)
{
	while (b_op)
	{
		if (b_op > 0)
		{
			ra(set);
			b_op--;
		}
		else
		{
			rra(set);
			b_op++;
		
		}
	}
}

void	exec_rotation(int a_op, int b_op, t_info *set)
{
	exec_same_rotation(&a_op, &b_op, set);
	ft_rotate_a(a_op, set);
	ft_rotate_b(b_op, set);
}

void	sort_b_to_a(set)
{
}

//a에서 b로 넘긴 이후 b에서 정렬하는 것이 필요한가?
//만약 연산횟수가 똑같다면 rb 혹은 rrb로 정렬해두는 것이 좋을듯
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
		get_min_operations(&a_op, &b_op, set);
		exec_rotation(a_op, b_op, set);
		pb(set);
	}
	sort_a_3(set);
	sort_b(set);
	sort_b_to_a(set);
}

// 처음 값들을 다 인덱스로 바꾸기?
//

int	get_target_idx(int target, t_stack *st)
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

void	insert_left_to_a(t_info *set)	
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
