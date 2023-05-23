/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:56:40 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/18 00:17:52 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_lst_size(t_env *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		++size;
	}
	return (size);
}

char	*get_env_str(t_env *env_lst)
{
	char	*temp;
	char	*env_str;

	if (env_lst == NULL)
		return (NULL);
	temp = ft_strjoin(env_lst->key, "=");
	env_str = ft_strjoin(temp, env_lst->value);
	free(temp);
	return (env_str);
}

char	**env_lst_to_arr(t_env *env_lst)
{
	int		i;
	char	**env;

	env = (char **)malloc(sizeof(char *) * (env_lst_size(env_lst) + 1));
	i = 0;
	while (env_lst)
	{
		env[i] = get_env_str(env_lst);
		env_lst = env_lst->next;
		++i;
	}
	env[i] = NULL;
	return (env);
}

void	env_lstdelone(t_env *lst)
{
	if (lst == NULL)
		return ;
	free(lst->key);
	free(lst->value);
	free(lst);
}

void	get_env_lst(t_env **env_lst, char **env)
{
	t_env	*new;
	int		i;

	i = 0;
	while (env[i])
	{
		new = env_lst_new(env[i]);
		env_lst_add_back(env_lst, new);
		++i;
	}
}
