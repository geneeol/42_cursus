/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:59:04 by dahkang           #+#    #+#             */
/*   Updated: 2022/10/01 21:44:39 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

#include <stdio.h>

//libft 꼭 가져올 것
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static int	print_char(char ch)
{
	return (write(1, &ch, 1));
}

static int	print_str(char *str)
{
	if (!str)
		str = "(null)";
	return (write(1, str, ft_strlen(str)));
}

static int	print_addr(void *ptr)
{
	unsigned long long	addr;

	addr = (unsigned long long)ptr;
	return (print_hex(addr, 'x'));
}


static int	ft_conversion(const char *format, int i, va_list ap)
{
	if (format[i] == 'c') 
		return (print_char(va_arg(ap, int)));
	else if (format[i] == 's')
		return (print_str(va_arg(ap, char *)));
	else if (format[i] == 'p')
		return (print_addr(va_arg(ap, void *)));
	else if (format[i] == 'd' || format[i] == 'i')
		return (print_decimal(va_arg(ap, int)));
	else if (format[i] == 'u')
		return (print_udecimal(va_arg(ap, unsigned int)));
	else if (format[i] == 'x' || format[i] == 'X')
		return (print_hex(va_arg(ap, unsigned int), format[i]));
	else if (format[i] == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int	i;
	int	setoff;
	int	tmp;
	va_list ap;

	i = 0;
	setoff = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			tmp = ft_conversion(format, i + 1, ap);
			if (tmp < 0)
				return (-1);
			i += 2;
			setoff += tmp - 2;
		}
		else
			if (write(1, &format[i++], 1) < 0)
				return (-1);
	}
	va_end(ap);
	return (i + setoff);
}
