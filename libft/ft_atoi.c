/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:11:33 by dahkang           #+#    #+#             */
/*   Updated: 2022/07/31 14:46:01 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char ch)
{
	if (ch == '\t' || ch == '\n' || ch == '\v'
		|| ch == '\f' || ch == '\r' || ch == ' ')
		return (1);
	else
		return (0);
}

//Omitting errno related matters
//ll_min is 10000~00000(2), and (int)ll_min == 0
//So even if LL_MIN pass as param, it happens to work correctly
//But this function needs to be modified,
//if it extends to a long-return-type function.
int	ft_atoi(const char *str)
{
	int			sign;
	long long	ret;

	sign = 1;
	ret = 0;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*(str++) == '-')
			sign *= -1;
	while (ft_isdigit(*str))
	{
		if (ret > LL_MAX / 10
			|| (ret == LL_MAX / 10 && *str - '0' > LL_MAX % 10))
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		ret = ret * 10 + (*(str++) - '0');
	}
	return ((int)(sign * ret));
}
