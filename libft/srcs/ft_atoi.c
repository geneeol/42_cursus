/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:11:33 by dahkang           #+#    #+#             */
/*   Updated: 2022/07/16 01:32:34 by dahkang          ###   ########.fr       */
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

//When a null pointer is passed as a parameter, a seg fault occurs.
//It is same as real atoi
//Omitting errno related matters
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
	while (ft_isdigit(*(str)))
	{
		//만약 음수 최솟값이 들어오면?
		//어차피 int쪽에서 먼저 오버플로우가 나서 문제되지 않음
		//단 이 코드는 strtol을 정확히 모방하진 못함
		if (ret >= 0 != ret * 10 + *str - '0' >= 0)
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
