#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "srcs/ft_memset.c"
#include "srcs/ft_strlen.c"
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

	//strlen
	printf(">----strlen-----<\n");
	printf("%zu ", ft_strlen("hello"));
	printf("%zu ", ft_strlen(""));
	printf("%zu \n", ft_strlen("a\n"));
	printf(">===============<\n\n\n");

	//atoi
	printf(">----atoi-----<\n");
	//char	*ptr = NULL;

	printf("123: %d\n", ft_atoi("  123"));
	printf("2147483647: %d\n", ft_atoi("2147383647"));
	printf("-2147384648: %d\n", ft_atoi("-2147383648"));
	printf("0: %d\n", ft_atoi("0"));
	//printf("NULL ptr: %d\n", ft_atoi(ptr));
	printf(">===============<\n\n\n");
	return 0;
}
