/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_exec_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:18:09 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/01 16:10:54 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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
