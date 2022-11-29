/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:56:33 by dahkang           #+#    #+#             */
/*   Updated: 2022/11/29 21:42:10 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>


#include <stdio.h>

void	print_exec(t_info *set)
{
	t_node	*cur;

	cur = set->op_queue->front;
	while (cur)
	{
		if (cur->data == SA)
			write(1, "SA\n", 3);
		else if (cur->data == SB)
			write(1, "SB\n", 3);
		else if (cur->data == SS)
			write(1, "SS\n", 3);
		else if (cur->data == PA)
			write(1, "PA\n", 3);
		else if (cur->data == PB)
			write(1, "PB\n", 3);
		else if (cur->data == RA)
			write(1, "RA\n", 3);
		else if (cur->data == RB)
			write(1, "RB\n", 3);
		else if (cur->data == RR)
			write(1, "RR\n", 3);
		else if (cur->data == RRA)
			write(1, "RRA\n", 4);
		else if (cur->data == RRB)
			write(1, "RRB\n", 4);
		else if (cur->data == RRR)
			write(1, "RRR\n", 4);
		cur = cur->next;
	}
}

int	main(int argc, char **argv)
{
	t_node	*cur;
	t_info	*set;

	set = input_parser(argc, argv);

	cur = set->st_a->front;
	/*
	printf("size: %lu\n", set->st_a->size);
	while (cur)
	{
		printf("data: %d\n", cur->data);
		cur = cur->next;
	}
	*/
	if (set->st_a->size <= 1 || is_sorted(set->st_a) == 1)
		return (0);
	/*else if (is_sorted(set->st_a) == 2)
		exec_rotation_a(-(set->st_a->size - 1), set);
	*/
	else if (set->st_a->size <= 4)
		sort_small(set);
	else
		sort_big(set);
	//노드가 없으면 출력 x
	print_exec(set);
	cur = set->st_a->front;
	while (cur)
	{
		printf("data: %d\n", cur->data);
		cur = cur->next;
	}
	//free_alloc(set);
	return (0);
}
