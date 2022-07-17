/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:19:46 by dahkang           #+#    #+#             */
/*   Updated: 2022/07/17 18:53:06 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define LL_MAX ((long long)(~0UL>>1))

# include <stdlib.h>
# include <stddef.h>

int		ft_isalpha(int ch);
int		ft_isdigit(int ch);
int		ft_isalnum(int ch);
int		ft_isascii(int ch);
int		ft_isprint(int ch);

size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_bzero(void *ptr, size_t n);
void	*ft_memset(void *ptr, int value, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dst_size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		ft_toupper(int ch);
int		ft_tolower(int ch);
char	*ft_strchr(const char *str, int ch);
char	*ft_strrchr(const char *str, int ch);
void	*ft_memchr(const void *str, int ch, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

int		ft_atoi(const char *str);

char	*ft_strdup(const char *str);
void	*ft_calloc(size_t count, size_t size);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);

#endif
