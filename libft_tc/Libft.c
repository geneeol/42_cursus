#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

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


void	*lstmap_f(void *content)
{
	(void)content;
	return ("OK !");
}


int	main()
{
	//memset
	char str[] = "almost every programmer should know memset!";

	printf(">----memset-----<\n");
	ft_memset(str, '-', 6);
	puts(str);
	ft_memset(str, 68, 6);
	puts(str);
	ft_memset(str, -5, 6);
	puts(str);
	printf(">===============<\n\n\n");

	//bzero
	printf(">-----bzero-----<\n");
	ft_bzero(str, 0);
	puts(str);
	ft_bzero(str, 5);
	printf("str[0], str[4], str[5] ascii: %d, %d, %d\n", str[0], str[4],str[5]);
	printf(">===============<\n\n\n");

	//memcpy
	char	dst[100];
	char	*src = "0123456789abcdef";
	char	*ret;
	printf(">-----memcpy-----<\n");
	ret = ft_memcpy(dst, src, 0);
	printf("garbage value: %s\n", dst);
	printf("ret: %p\n\n", ret);
	ret = ft_memcpy(dst, src, 5);
	printf("01234: %s\n", dst);
	printf("ret: %p\n\n", ret);
	ret = ft_memcpy(dst, src, 16);
	printf("0123456789abcdef: %s\n", dst);
	printf("dst[16]: %d\n", dst[16]);
	printf("ret: %p\n\n", ret);
	printf(">===============<\n\n\n");

	//strlen
	printf(">----strlen-----<\n");
	printf("%zu ", ft_strlen("hello"));
	printf("%zu ", ft_strlen(""));
	printf("%zu \n", ft_strlen("a\n"));
	printf(">===============<\n\n\n");

	//atoi
	printf(">----atoi-----<\n");
	//char	*ptr = NULL;

	/*
	printf("123: %d\n", ft_atoi("123"));
	printf("2147483647: %d\n", ft_atoi("2147383647"));
	printf("-2147384648: %d\n", ft_atoi("-2147383648"));
	printf("0: %d\n", ft_atoi("0"));
	printf("ft_atoi overflow: %d\n", ft_atoi("2000000000000000000000000000000\n"));
	printf("ft_atoi underflow: %d\n", ft_atoi("-2000000000000000000000000000000\n"));
	printf("ft_atoi u_long_max: %d\n", ft_atoi("18446744073709551614"));
	printf("ft_atoi long_min: %d\n", ft_atoi("-9223372036854775808\n"));
	printf("ft_atoi long_max: %d\n", ft_atoi("9223372036854775807\n"));
	*/
	printf("ft_atoi long_max - 1: %d\n", ft_atoi("9223372036854775806\n"));
	printf(">===atoi======<\n");
	printf("atoi overflow: %d\n", atoi("2000000000000000000000000000000\n"));
	printf("atoi underflow: %d\n", atoi("-2000000000000000000000000000000\n"));
	printf("atoi u_long_max: %d\n", atoi("18446744073709551614"));
	printf("atoi long_min: %d\n", atoi("-9223372036854775808\n"));
	printf("atoi long_max: %d\n", atoi("9223372036854775807\n"));
	printf("atoi long_max - 1: %d\n", atoi("9223372036854775806\n"));

	//printf("atoi: %d\n", atoi(ptr));
	printf(">===============<\n\n\n");

	//strlcpy
	//segfault occurs when dst & src
	char	*dst_a = 0;
	char	src_a[] = "hi";
	strlcpy(dst_a, src_a, 0);

	//strlcat
	char	*sc1 = 0;
	char	*sc2 = 0;
	char	*sc3 = "hello";
	char	*sc4 = "42world";

	printf(">----strlcat-----<\n");
	//dst가 널이고 src가 널포인터가 아니면서 dst_size가 0이면 세그폴트 발생 안함
	printf("ret: %lu\n", strlcat(sc1, sc3, 0));
	printf("ft_ret: %lu\n", ft_strlcat(sc2, sc3, 0));

	printf(">===============<\n\n\n");

	//strncmp
	char	*str1 = "abce";
	char	*str2 = "abc";
	printf("(abc, abc, 5): %d\n", ft_strncmp(str1, str2, 5));
	printf("(abce, abc, 5): %d\n", ft_strncmp(str1, str2, 5));

	//memcpy
	char	ptrc1[] = "hello";
	char	*ptrc2 = 0;
	//memcpy(ptrc1, ptrc2, 2);

	//memcmp
	char	*pt1 = 0;
	char	*pt2 = 0;

	printf("memcmp: %d\n", memcmp(pt1, pt2, 0));
	printf("memcmp: %d\n", memcmp("teste", "teste", 100));
	//printf("ft_memcmp: %d\n", ft_memcmp(pt1, pt2, 0));
	//printf("ft_memcmp: %d\n", ft_memcmp("teste", "teste", 6));
	printf(">===============<\n\n\n");


	//memmove
	char	strmm1[50] = "Hello42World";
	char	strmm2[50] = "Hello42World";
	char	*ptrmm1 = 0;
	char	*ptrmm2 = 0;
	printf(">----memmove-----<\n");
	printf("memmove: %s\n", memmove(strmm1, strmm1 + 3, 4));
	printf("ft_memmove: %s\n", ft_memmove(strmm2, strmm2 + 3, 4));
	//printf("memmove: %s\n", memmove(ptrmm1, ptrmm2, 0));
	//printf("ft_memmove: %s\n", ft_memmove(ptrmm1, ptrmm2, 0));
	printf("memmove: %s\n", memmove(strmm1 + 3, strmm1, 4));
	printf("ft_memmove: %s\n", ft_memmove(strmm2 + 3, strmm2, 4));
	printf(">===============<\n\n\n");

	//substr
	printf(">----substr-----<\n");
	char *sub = "i just want this part #############";
	size_t size = 22;
	char *ret_s = ft_substr(sub, 0, size);

	printf("len: %zu\n", ft_strlen(sub));
	printf("ret_s:%s\n", ret_s);
	if (!strncmp(ret_s, sub, size))
		printf("Success\n");
	else
		printf("Fail\n");
	printf(">===============<\n\n\n");

	//lst
	printf(">-----lst-----<\n");
	int	content[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int	idx;
	t_list	*head;
	t_list	*node;
	t_list	*curr;

	head = ft_lstnew((void *)(&content[0]));
	idx = 0;
	while (idx++ < 10)
	{
		node = ft_lstnew((void *)(&content[idx]));
		ft_lstadd_back(&head, node);
	}
	/*
	while (head -> next)
	{
		printf("content: %d\n", *((int *)head -> content));
		head = head -> next;
	}
	*/
	return 0;
}
