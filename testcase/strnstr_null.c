#include <stdio.h>
#include <string.h>
#include "../Libft/ft_strnstr.c"

#define PATH ../Libft

#include "../Libft/libft.h"

#include "../Libft/ft_memset.c"
#include "../Libft/ft_bzero.c"
#include "../Libft/ft_memcpy.c"
#include "../Libft/ft_strlen.c"
#include "../Libft/ft_isdigit.c"
#include "../Libft/ft_atoi.c"

#include "../Libft/ft_strncmp.c"
#include "../Libft/ft_memcmp.c"
#include "../Libft/ft_memmove.c"

#include "../Libft/ft_strlcpy.c"
#include "../Libft/ft_strlcat.c"
#include "../Libft/ft_substr.c"
#include "../Libft/ft_strdup.c"

#include "../Libft/ft_lstnew.c"
#include "../Libft/ft_lstadd_front.c"
#include "../Libft/ft_lstdelone.c"
#include "../Libft/ft_lstsize.c"
#include "../Libft/ft_lstlast.c"
#include "../Libft/ft_lstadd_back.c"



int	main(void)
{
	char	*s1 = "hi";
	char	*s2 = "fake";

	// needle이 널이면 len에 관계없이 항상 세그폴트
	// needle이 빈 문자열이면 s1이 널이어도 상관 없음
	//
	// needle이 빈 문자열이 아니고 haystack이 널이면 lend이 0일 때만 널을 리턴함 그 외의 경우 세그폴트 
	// 따라서 반복문 조건의 순서가 중요함
	// len이 0 이면 항상 널 리턴
	printf("addr: %p\n", strnstr(s1, s2, 0));
	printf("str: %s\n", strnstr(s1, s2, 0));
	printf("ft_addr: %p\n", ft_strnstr(s1, s2, 0));
	printf("ft_str: %s\n", ft_strnstr(s1, s2, 0));
	//printf("str: %s\n", strnstr(s1, s2, 100));
	return (0);
}
