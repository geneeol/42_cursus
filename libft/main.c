#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "includes/libft.h"

#include "srcs/ft_memset.c"
#include "srcs/ft_bzero.c"
#include "srcs/ft_memcpy.c"
#include "srcs/ft_strlen.c"
#include "srcs/ft_isdigit.c"
#include "srcs/ft_atoi.c"


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

	printf("123: %d\n", ft_atoi("123"));
	printf("2147483647: %d\n", ft_atoi("2147383647"));
	printf("-2147384648: %d\n", ft_atoi("-2147383648"));
	printf("0: %d\n", ft_atoi("0"));
	printf("ft_atoi overflow: %d\n", ft_atoi("2000000000000000000000000000000\n"));
	printf("ft_atoi underflow: %d\n", ft_atoi("-2000000000000000000000000000000\n"));
	printf("ft_atoi u_long_max: %d\n", ft_atoi("18446744073709551614"));
	printf(">===atoi======<\n");
	printf("atoi overflow: %d\n", atoi("2000000000000000000000000000000\n"));
	printf("atoi underflow: %d\n", atoi("-2000000000000000000000000000000\n"));
	//printf("atoi: %d\n", atoi(ptr));
	printf(">===============<\n\n\n");

	//strlcat
	//segfault occurs when dst & src
	char	*dst_a = 0;
	char	src_a[] = "hi";
	strlcpy(dst_a, src_a, 0);
	return 0;
}
