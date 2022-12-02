/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:12:50 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/02 15:08:23 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "structures.h"

//sort_utils.c
t_bool	is_asc_sorted(t_stack *st);
int		calc_total_op(int a, int b);

//sort_big.c
void	sort_big(t_info *set);

//sort_small.c
void	sort_a_3(t_info *set);
void	sort_small(t_info *set);

//sort_exec_rotation.c
void	exec_rotation_same(int *a_op, int *b_op, t_info *set);
void	exec_rotation_a(int a_op, t_info *set);
void	exec_rotation_b(int b_op, t_info *set);

//sort_algorithm.c

int		calc_proper_idx(int idx, int st_size);
int		calc_insertion_idx(t_info *set, int target);
void	calc_min_operations(int *a_op, int *b_op, t_info *set);

#endif
