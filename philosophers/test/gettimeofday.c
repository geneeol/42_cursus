#include <stdio.h>
#include <sys/time.h>

unsigned long long	get_cur_time(void)
{
	struct timeval		tp;
	unsigned long long	cur_time;

	gettimeofday(&tp, NULL);
	printf("tv_sec: %ld\n", tp.tv_sec);
	printf("tv_usec: %d\n", tp.tv_usec);
	cur_time = tp.tv_sec * 1000000 + tp.tv_usec;
	return (cur_time);
}

int	main(void)
{
	printf("ret: %lld\n", get_cur_time());
}
