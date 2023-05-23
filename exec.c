/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:08:19 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/23 22:39:02 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_command(t_process *proc, int i, t_info *info, t_env **env_lst)
{
	char	**path;
	char	**env;
	char	**command;
	char	*full_path;

	path = get_path(*env_lst);
	close_unused_pipes(i, info->process_num, proc);
	redirect_process(proc, info, i);
	command = info->commands[i].command;
	if (command[0] == NULL)
		exit(0);
	if (builtin_func(info, command, env_lst))
		exit (0);
	full_path = execute_check(command[0], path);
	free(command[0]);
	command[0] = full_path;
	env = env_lst_to_arr(*env_lst);
	execve(command[0], command, env);
	perror(command[0]);
	exit(1);
}

void	fork_and_execute(t_process *proc, t_info *info, t_env **env_lst)
{
	int		i;

	i = 0;
	while (i < info -> process_num)
	{
		proc[i].pid = fork();
		if (proc[i].pid == -1)
			print_error("fork", 0);
		if (proc[i].pid == 0)
			execute_command(proc, i, info, env_lst);
		if (i == 0)
			close(proc[0].fd[1]);
		else if (i == info -> process_num - 1)
			break ;
		else
		{
			close(proc[i - 1].fd[0]);
			close(proc[i].fd[1]);
		}
		++i;
	}
}

int	check_builtin(char **command)
{
	if (command[0] == NULL)
		return (0);
	if (ft_strncmp(command[0], "exit", 5) == 0)
		return (1);
	else if (ft_strncmp(command[0], "env", 4) == 0 && command[1] == NULL)
		return (1);
	else if (ft_strncmp(command[0], "export", 7) == 0)
		return (1);
	else if (ft_strncmp(command[0], "unset", 6) == 0)
		return (1);
	else if (ft_strncmp(command[0], "pwd", 4) == 0)
		return (1);
	else if (ft_strncmp(command[0], "cd", 3) == 0)
		return (1);
	else if (ft_strncmp(command[0], "echo", 5) == 0 && command[1] && ft_strncmp(command[1], "-n", 3) == 0)
		return (1);
	return (0);
}

int	check_num(char *num)
{
	if (*num == '-' && *num)
		num++;
	while (*num)
	{
		if (!ft_isdigit(*num))
			return (0);
		num++;
	}
	return (1);
}

int	exec_single_builtin(t_info *info, t_env **env_lst)
{
	char	**command;
	unsigned char exit_num;

	command = info->commands[0].command;
	if (!check_builtin(command))
		return (0);
	redirect_process(NULL, info, 0);
	if (ft_strncmp(command[0], "exit", 5) == 0)
	{
		ft_putendl_fd("exit", 1);
		exit_num = 0;
		if (command[1])
		{
			if (command[2])
			{
				minishell_error_not_exit(command[0], "too many arguments", 1);
				return (-1);
			}
			unlink_heredocs(info);
			if (!check_num(command[1]))
				minishell_arg_error(command[0], command[1], "numeric argument required", 255);
			exit_num = (unsigned char)ft_atoi(command[1]);
		}
		unlink_heredocs(info);
		exit(exit_num);
	}
	return (builtin_func(info, command, env_lst));
}
