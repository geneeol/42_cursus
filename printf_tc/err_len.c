#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ft_strlen.c"
#include "../ft_printf/ft_printf.h"
#include "../ft_printf/ft_printf.c"
#include "../ft_printf/ft_printf_str.c"
#include "../ft_printf/ft_printf_numeric.c"
#include "../ft_printf/ft_printf_utils.c"
#include <stdio.h>

int	main(void)
{
	char	*str;
	
	str = (char *)malloc(2147483647);
	memset(str, '~', 2147483647);

	//str 길이가 int_max면 에러
	//총 길이가 int_max보다 작으면 ok
	//printf("ret: %d\n", printf("%s", str));
	printf("ret: %d\n", ft_printf("%s", str));
	return (0);
}
