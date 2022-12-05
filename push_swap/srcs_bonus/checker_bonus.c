/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:17:38 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/05 13:54:34 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	exec_operation(t_info *set, int idx)
{
	const t_operations	op_list[] = {
		sa, sb, ss,
		pa, pb,
		ra, rb, rr,
		rra, rrb, rrr
	};

	op_list[idx](set);
}

int	get_excuted_op(char *op)
{
	const char	*operations[] = {
		"sa\n", "sb\n", "ss\n",
		"pa\n", "pb\n",
		"ra\n", "rb\n", "rr\n",
		"rra\n", "rrb\n", "rrr\n",
		0
	};
	int			idx;

	idx = 0;
	while (operations[idx])
	{
		if (ft_strncmp(operations[idx], op, ft_strlen(op)) == 0)
			return (idx);
		idx++;
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	t_info	*set;
	char	*op;
	int		idx;

	if (argc < 2)
		exit(EXIT_FAILURE);
	set = input_parser(argc, argv);
	op = get_next_line(0);
	while (op)
	{
		idx = get_excuted_op(op);
		if (idx == -1)
			ft_err_exit(0, EXIT_FAILURE);
		exec_operation(set, idx);
		free(op);
		op = get_next_line(0);
	}
	if (set->st_b->size == 0 && is_asc_sorted(set->st_a))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_info(set);
	set = 0;
	return (0);
}
