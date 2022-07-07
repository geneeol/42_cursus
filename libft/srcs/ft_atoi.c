/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:11:33 by dahkang           #+#    #+#             */
/*   Updated: 2022/07/07 20:11:34 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char ch)
{
	if (ch == '\t' || ch == '\n' || ch == '\v'
		|| ch == '\f' || ch == '\r' || ch == ' ')
		return (1);
	else
		return (0);
}

int	is_number(char ch)
{
	if ('0' <= ch && ch <= '9')
		return (1);
	else
		return (0);
}

//When a null pointer is passed as a parameter, a seg fault occurs.
//Omitting errno related matters
int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	ret;

	i = 0;
	sign = 1;
	ret = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (is_number(str[i]))
	{
		ret *= 10;
		ret += sign * (str[i] - '0');
		i++;
	}
	return (ret);
}
