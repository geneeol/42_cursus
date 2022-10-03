#include <stdio.h>

#include "../ft_printf/ft_printf.h"
#include "../ft_printf/ft_printf.c"
#include "../ft_printf/ft_printf_str.c"
#include "../ft_printf/ft_printf_numeric.c"
#include "../ft_printf/ft_printf_utils.c"

int	main(void)
{
	printf("com ret: %d\n", printf("hi%"));
	printf("mine ret: %d\n", ft_printf("hi%"));
	printf("com ret: %d\n", printf("hi%", 'c'));
	printf("mine ret: %d\n", ft_printf("hi%", 'c'));
	printf("com ret: %d\n", printf("hi%q", 'c'));
	printf("mine ret: %d\n", ft_printf("hi%q", 'c'));
	printf("com ret: %d\n", printf("hi%qqello"));
	printf("com ret: %d\n", printf("hi%qqello", 'c'));
	printf("com ret: %d\n", printf("h%eeello"));
	printf("mine ret: %d\n", ft_printf("h%eeello"));
	printf("com ret: %d\n", printf("h%aaello"));
	return (0);
}
