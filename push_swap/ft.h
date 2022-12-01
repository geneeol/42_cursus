/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:45:25 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/01 16:36:29 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <unistd.h>

typedef int	t_bool;

# define LL_MAX 0x7FFFFFFFFFFFFFFF

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define FALSE 0
# define TRUE 1

enum e_op
{
	SA = 0,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
};

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node		*front;
	t_node		*rear;
	size_t		size;
}	t_stack;

typedef struct s_info
{
	t_stack	*st_a;
	t_stack	*st_b;
	t_stack	*op_queue;
}	t_info;

void	ft_err_exit(int err_status);
char	**ft_split(char const *str, char ch);

//deque.c
t_node	*ft_creat_node(int data);
int		get_front(t_stack *stk);
int		get_rear(t_stack *stk);
int		pop_front(t_stack *stk);
int		pop_rear(t_stack *stk);
t_bool	push_front(t_stack *stk, int data);
t_bool	push_rear(t_stack *stk, int data);
void	stk_clear(t_stack *stk);

//init
t_stack	*init_stack(void);
t_info	*init_info(void);



//parser
t_info	*input_parser(int argc, char **argv);
t_bool	atoi_is_valid(char const *str, int *res);
t_bool	is_duplicate(t_stack *stk, int res);
void	free_args(char **args);

//operations.c
t_bool	swap(t_stack *stk);
t_bool	sa(t_info *set);
t_bool	sb(t_info *set);
t_bool	ss(t_info *set);
t_bool	push(t_stack *stk1, t_stack *stk2);
t_bool	pa(t_info *set);
t_bool	pb(t_info *set);
t_bool	rotate(t_stack *stk);
t_bool	ra(t_info *set);
t_bool	rb(t_info *set);
t_bool	rr(t_info *set);
t_bool	reverse_rotate(t_stack *stk);
t_bool	rra(t_info *set);
t_bool	rrb(t_info *set);
t_bool	rrr(t_info *set);

/********sort*********/

//sort_utils.c
int		is_asc_sorted(t_stack *st);
int		abs(int n);
int		abs_max(int a, int b);
int		calc_total_op(int a, int b);

void	exec_rotation_a(int a_op, t_info *set);
void	sort_small(t_info *set);

//sort.c
void	align_b(t_info *set);
void	sort_b_to_a(t_info *set);
void	sort_big(t_info *set);

void	sort_a_3(t_info *set);

//sort_exec_rotation.c
void	exec_rotation_same(int *a_op, int *b_op, t_info *set);
void	exec_rotation_a(int a_op, t_info *set);
void	exec_rotation_b(int b_op, t_info *set);

//sort_algorithm.c
int		calc_proper_idx(int idx, int st_size);
int		calc_idx_sorted(t_info *set, int target);
int		calc_idx_unsorted(t_info *set, int target);
int		calc_insertion_idx(t_info *set, int target);
void	calc_min_operations(int *a_op, int *b_op, t_info *set);

#endif
