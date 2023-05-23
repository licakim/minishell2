/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:58:33 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/18 23:54:26 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_lst_add_back(t_env **lst, t_env *new)
{
	t_env	*temp;

	if (new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

t_env	*env_lst_new(char *env)
{
	t_env	*new_lst;
	int		idx;

	new_lst = (t_env *)malloc(sizeof(t_env));
	idx = get_first_idx(env, '=');
	new_lst->key = ft_substr(env, 0, idx);
	new_lst->value = ft_substr(env, idx + 1, ft_strlen(env) - 1 - idx);
	new_lst->next = NULL;
	return (new_lst);
}

void	print_env(char **env, int env_num)
{
	int	i;

	i = 0;
	while (i < env_num)
	{
		if (env[i])
			ft_putendl_fd(env[i], 1);
		++i;
	}
}

t_env	*get_lst_by_key(t_env *env_lst, char *key)
{
	while (env_lst)
	{
		if (ft_strncmp(env_lst->key, key, (ft_strlen(key) + 1)) == 0)
			return (env_lst);
		env_lst = env_lst->next;
	}
	return (NULL);
}

void	env_lst_unset(t_env **env_lst, char **str)
{
	t_env	*lst;
	t_env	*prev;
	int		i;

	i = 0;
	while (str[i])
	{
		lst = *env_lst;
		while (lst)
		{
			if (ft_strncmp(lst->key, str[i], (ft_strlen(lst->key) + 1)) == 0)
			{
				if (lst == *env_lst)
					*env_lst = NULL;
				else
					prev->next = lst->next;
				env_lstdelone(lst);
				break ;
			}
			prev = lst;
			lst = lst->next;
		}
		++i;
	}
}
