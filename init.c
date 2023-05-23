/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 05:38:27 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/18 23:54:05 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int exit_status;

static void	sigint_handler(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	exit_status = 1;
}

void	init(int argc, char *argv[], char **env, t_env **env_lst)
{
	(void)argv;
	if (argc != 1)
	{
		ft_putendl_fd("Error: No arguments should be provided.", 2);
		exit(1);
	}
	*env_lst = NULL;
	get_env_lst(env_lst, env);
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}
