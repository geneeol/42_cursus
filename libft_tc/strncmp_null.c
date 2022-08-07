#include <stdio.h>
#include <string.h>
#include "../Libft/ft_strncmp.c"

int	main(void)
{
	char	*s1 = 0;
	char	*s2 = 0;

	//n이 0이면 항상 0 리턴
	printf("ret: %d\n", strncmp(s1, s2, 0));
	printf("ret: %d\n", ft_strncmp(s1, s2, 0));
	return (0);
}
