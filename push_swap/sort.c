/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:27:40 by dahkang           #+#    #+#             */
/*   Updated: 2022/11/29 22:58:32 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"


#include <stdio.h>

int	is_sorted(t_stack *st)
{
	t_node	*cur;
	int		status;

	cur = st->front;
	status = 0;
	while (cur->next)
	{
		if (cur->data < cur->next->data)
		{
			if (status == 2)
				return (0);
			status = 1;

		}
		else
		{
			if (status == 1)
				return (0);
			status = 2;
		}
		cur = cur->next;
	}
	return (status);
}

int	abs_max(int a, int b)
{
	if (a < 0 && b < 0)
	{
		if (a > b)
			return (-b);
		else
			return (-a);
	}
	else
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
}

int	abs(int n)
{
	if (n > 0)
		return (n);
	else
		return (-n);
}

int	op_tot(int a, int b)
{
	if (a > 0 && b > 0)
		return (abs_max(a, b));
	else if (a < 0 && b < 0)
		return (abs_max(a,b));
	else
		return (abs(a-b));
}

int	get_proper_idx(int idx, int st_size)
{
	int	ret;

	if (idx > st_size / 2)
		ret = (st_size - idx) * -1;
	else
		ret = idx;
	return (ret);
}

//고쳐야 함
int	get_insertion_loc_sorted(t_info *set, int target)
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
			return (get_proper_idx(idx, set->st_b->size));
		cur = cur->next;
	}
	// 이걸 넣어야 하나?
	return (-100000);
}


//고쳐야 함
int	get_insertion_loc_unsorted(t_info *set, int target)
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
				return (get_proper_idx(idx, set->st_b->size));
		}
		else
		{
			if (target < cur->prev->data || target > cur->data)
				return (get_proper_idx(idx, set->st_b->size));
		}
		cur = cur->next;
	}
	//이거 넣어야 하나?
	return (-100000);
}

// b가 전부 정렬되어있느냐, 중간에 역순인 부분이 있느냐에 따라 또 나뉨
// 몇번째 인덱스에 넣을지 찾는게 생각보다 까다로움.........
int	get_insertion_loc(t_info *set, int target)
{
	int		b_idx;

	//0번 인덱스는 맨위값과 맨 아래값을 비교해야함
	//나머지 인덱스는 현재값과 그 이전값.
	//만약 이전값이 현재값보다 크다면 그 경우를 예외처리 해주어야함
	//
	if (get_front(set->st_b) > get_rear(set->st_b))
		b_idx = get_insertion_loc_sorted(set, target);
	else
		b_idx = get_insertion_loc_unsorted(set, target);
	return (b_idx);
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
		b_idx = get_insertion_loc(set, cur->data);
		a_idx = get_proper_idx(idx, set->st_a->size);
		if (idx == 0 || op_tot(a_idx, b_idx) < op_tot(*a_op, *b_op))
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

void	exec_rotation_same(int *a_op, int *b_op, t_info *set)
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

void	exec_rotation_a(int a_op, t_info *set)
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

void	exec_rotation_b(int b_op, t_info *set)
{
	while (b_op)
	{
		if (b_op > 0)
		{
			rb(set);
			b_op--;
		}
		else
		{
			rrb(set);
			b_op++;
		
		}
	}
}

void	sort_b(t_info *set)
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
	idx = get_proper_idx(idx, set->st_b->size);
	exec_rotation_b(idx, set);
}

void	sort_b_to_a(t_info *set)
{
	while (get_front(set->st_b) < get_rear(set->st_a))
		rra(set);
	while (set->st_b->size)
	{
		pa(set);
		while (set->st_b->size && get_front(set->st_b) < get_rear(set->st_a) && get_rear(set->st_a) < get_front(set->st_a)) 
			rra(set);
	}
	while (get_front(set->st_a) > get_rear(set->st_a))
		rra(set);
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
		exec_rotation_same(&a_op, &b_op, set);
		exec_rotation_a(a_op, set);
		exec_rotation_b(b_op, set);
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
