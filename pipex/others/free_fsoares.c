//이거 하려면 static선언 해제해주어야 함
void	free_strs(char *strs[]);

static void	free_info(t_proc *proc_info)
{
	int	i;

	i = -1;
	while (++i < proc_info->cmd_cnt)
	{
		free(proc_info->cmd_table[i].path);
		free_strs(proc_info->cmd_table[i].argv);
	}
	free(proc_info->cmd_table);
	free(proc_info);
}

static int	wait_children(t_proc *proc_info)
{
	int	i;
	int	status;
	int	exit_status;

	i = -1;
	while (++i < proc_info->cmd_cnt)
	{
		if (proc_info->pid == wait(&status))
			exit_status = WEXITSTATUS(status);
	}
	free_info(proc_info);
	return (exit_status);
}

