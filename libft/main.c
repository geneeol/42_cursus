#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "srcs/ft_memset.c"
#include "srcs/ft_strlen.c"


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

	printf(">----strlen-----<\n");
	printf("%zu ", ft_strlen("hello"));
	printf("%zu ", ft_strlen(""));
	printf("%zu \n", ft_strlen("a\n"));
	printf(">===============<\n\n\n");

	return 0;
}
