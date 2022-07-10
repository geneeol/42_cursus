/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:19:46 by dahkang           #+#    #+#             */
/*   Updated: 2022/07/10 17:23:19 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_isalpha(int ch);
int	ft_isdigit(int ch);
int	ft_isalnum(int ch);
int	ft_isascii(int ch);
int	ft_isprint(int ch);

size_t	ft_strlen(const char *str)
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_bzero(void *ptr, size_t n);
void	*ft_memset(void *ptr, int value, size_t len);
void	*memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dst_size);

int	ft_toupper(int ch);
int	ft_tolower(int ch);
char	*ft_strchr(const char *str, int ch);
char	*ft_strrchr(const char *str, int ch);

int	ft_atoi(const char *str);
