/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:33:32 by dahkang           #+#    #+#             */
/*   Updated: 2022/07/10 16:37:40 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int ch)
{
	int	diff;

	diff = 'a' - 'A';
	if ('a' <= ch && ch <= 'z')
		return (ch - diff);
	else
		return (ch);
}