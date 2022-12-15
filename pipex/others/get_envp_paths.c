#include "../libft/includes/libft.h"
#include <stdio.h>

char	**get_envp_paths(char *envp[])
{
	char	**envp_paths;
	int		i;
	
	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (ft_split(envp[i] + 5, ':'));
	}
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		i;
	char	**strs;

	strs = get_envp_paths(envp);
	i = -1;
	while (strs[++i])
		printf("strs[%d]: %s\n", i, strs[i]);
}
