/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:56:33 by dahkang           #+#    #+#             */
/*   Updated: 2022/11/28 17:05:24 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_info	*set;

	set = input_parser(argc, argv);
	if (set->st_a->size <= 1 || is_sorted(set->st_a))
		return (0);
	else if (set->st_a->size <= 4)
		sort_small(set);
	else
		sort_big(set);
	//노드가 없으면 출력 x
	print_exec(set);
	free_alloc(set);
	return (0);
}
