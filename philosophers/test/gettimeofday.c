#include <stdio.h>
#include <sys/time.h>

int	get_cur_time(void)
{
	struct timeval	tp;
	int				cur_time;

	gettimeofday(&tp, NULL);
	cur_time = tp.tv_sec * 1000000 + tp.tv_usec;
	return (cur_time);
}

int	main(void)
{
	printf("ret: %d\n", get_cur_time());
}
