/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:01:25 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/20 21:24:44 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_redirect
{
	int					type;
	char				*fd;
	char				*file;
	struct s_redirect	*next;
}	t_redirect;

typedef struct s_command
{
	char				**command;
	t_redirect			*input;
	t_redirect			*output;
}	t_command;

typedef struct s_info
{
	int			process_num;
	int			heredoc_num;
	char		**heredocs;
	t_command	*commands;
}	t_info;

typedef struct s_process
{
	int		n;
	pid_t	pid;
	int		fd[2];
}	t_process;

int	check_num(char *num);
void	init(int argc, char *argv[], char **env, t_env **env_lst);
void	get_env_lst(t_env **env_lst, char **env);
int		get_first_idx(char *str, char c);
char	**get_path(t_env *env_lst);
void	env_lst_add_back(t_env **lst, t_env *new);
t_env	*env_lst_new(char *env);
void	print_env(char **env, int env_num);
void	minishell_error_not_exit(char *command, char *err_msg, int exit_num);
void	minishell_error(char *command, char *err_msg, int exit_num);
void	minishell_arg_error(char *command, char *arg, char *err_msg, int exit_num);
void	minishell_perror(char *msg, int exit_num);
void	print_error(char *msg, int status);
int		unlink_heredocs(t_info *comm_info);
int		create_heredoc_temp(t_info *info, t_env *env_lst);
void	join_env(char **line, char *env_value, int start, int end);
void	expand_env(char **line, t_env *env_lst);
void	redirect_process(t_process *proc, t_info *info, int i);
int		fd_check(char *fd);
int		env_lst_size(t_env *lst);
char	*get_env_str(t_env *env_lst);
char	**env_lst_to_arr(t_env *env_lst);
void	env_lstdelone(t_env *lst);
t_env	*get_lst_by_key(t_env *env_lst, char *key);
void	env_lst_unset(t_env **env_lst, char **str);
void	create_pipe(t_process *process, int process_cnt);
void	close_unused_pipes(int i, int process_num, t_process *process);
int		unlink_heredocs(t_info *comm_info);
void	wait_all_child(int process_cnt, t_process *process);
int		fd_check(char *fd);
char	*execute_check(char *command, char **path);
void	execute_command(t_process *proc, int i, t_info *info, t_env **env_lst);
void	fork_and_execute(t_process *proc, t_info *info, t_env **env_lst);
int		exec_single_builtin(t_info *info, t_env **env_lst);
int		builtin_func(t_info *info, char **command, t_env **env_lst);

#endif
