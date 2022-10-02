/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:57:52 by dahkang           #+#    #+#             */
/*   Updated: 2022/10/02 22:47:29 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_strlen(char *);


int		print_char(char ch);
int		print_str(char *str);
int		print_decimal(int n);
int		print_udecimal(unsigned int n);
int		print_hex(unsigned int n, char button);
int		pf_len(long long n, int scale);
void	pf_itoa(int n, char *str, int flag);
void	pf_itoa_hex(unsigned long long n, char *str, char button);

#endif
