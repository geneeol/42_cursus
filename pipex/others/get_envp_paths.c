#include "../libft/includes/libft.h"
#include <stdio.h>

char	**get_envp_paths(char *envp[])
{
	char	**envp_paths;
	int		i;
	
	i = -1;
	printf("envp: %p", envp);
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5 == 0))
			return (ft_split(envp[i] + 5, ':'));
	}
	return (0);
}
//
