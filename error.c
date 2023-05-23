/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 23:30:46 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/20 20:51:03 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int exit_status;

void	minishell_error_not_exit(char *command, char *err_msg, int exit_num)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(err_msg, 2);
	exit_status = exit_num;
}

void	minishell_error(char *command, char *err_msg, int exit_num)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(err_msg, 2);
	exit_status = exit_num;
	exit(exit_num);
}

void	minishell_arg_error(char *command, char *arg, char *err_msg, int exit_num)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(err_msg, 2);
	exit_status = exit_num;
	exit(exit_num);
}

void	minishell_perror(char *msg, int exit_num)
{
	ft_putstr_fd("minishell: ", 2);
	perror(msg);
	exit_status = exit_num;
	exit(exit_num);
}

void	print_error(char *msg, int status)
{
	if (status == 0)
		perror(msg);
	else if (status == 1)
		ft_putendl_fd(msg, 2);
	exit_status = 1;
	exit(1);
}
