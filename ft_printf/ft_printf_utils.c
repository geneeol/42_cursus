/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:45:32 by dahkang           #+#    #+#             */
/*   Updated: 2022/10/02 22:50:10 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

//이거 unsigned ll 로 받으면 d가 터짐
//long long 으로 받으면 p랑 u에서 터짐
int	pf_len(long long n, int scale)
{
	int	len;

	len = 1;
	while (n / scale)
	{
		len++;
		n /= scale;
	}
	return (len);
}

void	pf_itoa_hex(unsigned long long n, char *str, char button)
{
	int		i;

	i = pf_len(n, 16);
	str[i] = 0;
	while (--i >= 0)
	{
		if (button == 'x')
			str[i] = "0123456789abcdef"[n % 16];
		else if (button == 'X')
			str[i] = "0123456789ABCDEF"[n % 16];
		n /= 16;
	}
}

void	pf_itoa(int n, char *str, int flag)
{
	int				i;
	unsigned int	nb;

	if (n < 0 && flag == 0)
		nb = -n;
	else if (flag == 0) 
		nb = n;
	else
		nb = n;
	i = pf_len(n, 10) + (n < 0);
	str[i] = 0;
	while (--i >= (n < 0))
	{
		str[i] = "0123456789"[nb % 10];
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
}
