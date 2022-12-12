#include <stdio.h>

typedef	struct s_struct
{
	int		num;
	char	*str;
}	t_struct;

void	change(t_struct info)
{
	info.num = 20;
	info.str = "hi\n";
	printf("info.num: %d\n", info.num);
	printf("info.str: %s\n", info.str);
}

int	main(void)
{
	t_struct	info;

	info.num = 10;
	info.str = "hello\n";
	printf("info.num: %d\n", info.num);
	printf("info.str: %s\n", info.str);
	change(info);
	printf("info.num: %d\n", info.num);
	printf("info.str: %s\n", info.str);
	return (0);
}
