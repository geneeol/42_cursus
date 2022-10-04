/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:57:52 by dahkang           #+#    #+#             */
/*   Updated: 2022/10/04 17:21:11 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_strlen(char *str);
int		ft_printf(const char *format, ...);
int		print_char(char ch);
int		print_str(char *str);
int		print_decimal(int n);
int		print_udecimal(unsigned int n);
int		print_hex(unsigned int n, char button);
void	pf_itoa(int n, char str[]);
void	pf_itoa_u(unsigned int n, char str[]);
void	pf_itoa_hex(unsigned long long n, char str[], char specifier);

#endif
