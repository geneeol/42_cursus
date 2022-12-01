/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:05:17 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/01 18:24:18 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>
# include "structures.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

t_info	*input_parser(int argc, char **argv);
t_bool	atoi_is_valid(char const *str, int *res);
t_bool	is_duplicate(t_stack *stk, int res);
void	free_args(char **args);

#endif
