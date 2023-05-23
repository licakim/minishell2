/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:06:29 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/23 22:12:26 by hyunjki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fd_check(char *fd)
{
	int	fd_num;

	if (ft_strlen(fd) > 3)
		minishell_error(fd, strerror(9), 1);
	fd_num = ft_atoi(fd);
	if (fd_num >= 256)
		minishell_error(fd, strerror(9), 1);
	return (fd_num);
}

char	*execute_check(char *command, char **path)
{
	int		i;
	char	*full_path;

	if (command == NULL)
		return (NULL);
	if (command[0] == '.' || command[0] == '/')
	{
		if (access(command, X_OK) != 0)
			minishell_perror(command, 126);
		return (ft_strdup(command));
	}
	i = 0;
	while (path[i])
	{
		full_path = ft_strjoin(path[i], command);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		++i;
	}
	minishell_error(command, "command not found", 127);
	return (NULL);
}
