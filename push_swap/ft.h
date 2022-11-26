/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:45:25 by dahkang           #+#    #+#             */
/*   Updated: 2022/11/26 22:32:22 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <unistd.h>



# include <stdio.h>

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
t_stack	*init_stack(void);
t_info	*init_info(void);
t_info	*input_parser(int argc, char **argv);
int		pop_front(t_stack *stk);
int		pop_rear(t_stack *stk);
t_bool	push_front(t_stack *stk, int data);
t_bool	push_rear(t_stack *stk, int data);
void	stk_clear(t_stack *stk);

//operations.c
t_bool	push(t_stack *stk1, t_stack *stk2);
t_bool	push_a(t_info *set);
t_bool	push_b(t_info *set);
t_bool	reverse_rotate(t_stack *stk);
t_bool	rotate(t_stack *stk);
t_bool	swap(t_stack *stk);
t_bool	swap_a(t_info *set);
t_bool	swap_b(t_info *set);
t_bool	ss(t_info *set);
t_bool	rotate_a(t_info *set);
t_bool	rotate_b(t_info *set);
t_bool	rr(t_info *set);
t_bool	reverse_rotate_a(t_info *set);
t_bool	reverse_rotate_b(t_info *set);
t_bool	rrr(t_info *set);
#endif
