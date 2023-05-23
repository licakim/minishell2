/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:56:21 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/17 21:08:00 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_first_idx(char *str, char c)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] == c)
			return (idx);
		++idx;
	}
	return (-1);
}

char	**get_path(t_env *env_lst)
{
	char	**path;
	int		i;
	char	*temp;

	while (env_lst && ft_strncmp(env_lst->key, "PATH", 5) != 0)
		env_lst = env_lst->next;
	if (env_lst)
		path = ft_split(env_lst->value, ':');
	else
		return (NULL);
	i = 0;
	while (path[i])
	{
		temp = path[i];
		path[i] = ft_strjoin(path[i], "/");
		free(temp);
		++i;
	}
	return (path);
}
