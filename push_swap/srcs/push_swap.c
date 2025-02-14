/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:56:33 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/06 09:17:36 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/data_structure.h"
#include "../includes/operations.h"
#include "../includes/sort.h"
#include "../includes/parser.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_info	*set;

	if (argc < 2)
		exit(EXIT_FAILURE);
	set = input_parser(argc, argv);
	if (set->st_a->size <= 1 || is_asc_sorted(set->st_a) == TRUE)
	{
		free_info(set);
		set = 0;
		return (0);
	}
	else if (set->st_a->size <= 4)
		sort_small(set);
	else
		sort_big(set);
	print_op(set);
	free_info(set);
	set = 0;
	return (0);
}
