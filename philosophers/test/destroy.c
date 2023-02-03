#include <stdio.h>
#include <pthread.h>
#include <sys/_pthread/_pthread_mutex_t.h>

int	main(void)
{
	pthread_mutex_t	lock;

	printf("ret: %d\n", pthread_mutex_destroy(&lock));
	return (0);
}
