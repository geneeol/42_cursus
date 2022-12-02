/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:24:59 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/02 15:31:54 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/libft.h"
#include "../../includes/data_structure.h"

static void	print_cmd_name(int op)
{
	if (op == SA)
		ft_putendl_fd("sa", 1);
	else if (op == SB)
		ft_putendl_fd("sb", 1);
	else if (op == SS)
		ft_putendl_fd("ss", 1);
	else if (op == PA)
		ft_putendl_fd("pa", 1);
	else if (op == PB)
		ft_putendl_fd("pb", 1);
	else if (op == RA)
		ft_putendl_fd("ra", 1);
	else if (op == RB)
		ft_putendl_fd("rb", 1);
	else if (op == RR)
		ft_putendl_fd("rr", 1);
	else if (op == RRA)
		ft_putendl_fd("rra", 1);
	else if (op == RRB)
		ft_putendl_fd("rrb", 1);
	else if (op == RRR)
		ft_putendl_fd("rrr", 1);
}

void	print_op(t_info *set)
{
	t_node	*cur;

	cur = set->op_queue->front;
	while (cur)
	{
		print_cmd_name(cur->data);
		cur = cur->next;
	}
}
