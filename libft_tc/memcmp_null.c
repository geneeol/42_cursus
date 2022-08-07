#include <stdio.h>
#include <string.h>
#include "../Libft/ft_memcmp.c"

int	main(void)
{
	char	*s1 = 0;
	char	*s2 = 0;

	printf("ret: %d\n", memcmp(s1, s2, 0));
	printf("ft: %d\n", ft_memcmp(s1, s2, 4));
	return (0);
}
