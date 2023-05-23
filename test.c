/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:33:01 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/21 13:27:40 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include<stdio.h>

int	exit_status;

char	*read_command(void)
{
	char	*command;

	command = readline("minishell$ ");
	if (command == NULL)
	{
		ft_putstr_fd("\x1b[1A", 1);
		ft_putstr_fd("\033[11C", 1);
		write(1, "exit\n", 5);
		exit(0);
	}
	if (ft_strlen(command) != 0)
		add_history(command);
	return (command);
}

void	add_list(char *str, t_list **cmds)
{
	t_list	*new;

	new = ft_lstnew(str);
	ft_lstadd_back(cmds, new);
}

int	is_not_sep(char c)
{
	if (c == ' ' || c == '<' || c == '>' || c == '|')
		return (0);
	return (1);
}

int	ft_strcmp(char	*s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}

int	check_end(char *command, int i, char c)
{
	int	len;

	len = 1;
	i++;
	while (command[i])
	{
		if (command[i++] == c)
			return (len);
		len++;
	}
	return (0);
}

int	check_prev(char *command, int i, t_list *cmds)
{
	t_list	*temp;
	char	*c;
	int		k;

	k = 0;
	if (i - 1 >= 0 && ft_isdigit(command[i - 1]))
	{
		temp = ft_lstlast(cmds);
		c = temp -> content;
		while (c[k])
		{
			if (!ft_isdigit(c[k]))
				return (0);
			k++;
		}
		return (1);
	}
	return (0);
}

void	error_m(int c)
{
	printf("Error%d\n", c);
	exit(1);
}

void	check_sep(char *sep)
{
	if (sep[0] == '<')
		if (!(ft_strcmp(sep, "<") || ft_strcmp(sep, "<<")))
			error_m(2);
	if (sep[0] == '>')
		if (!(ft_strcmp(sep, ">") || ft_strcmp(sep, ">>")))
			error_m(3);
}

int	find_sep(char *command, int start, int i, t_list **cmds)
{
	char	*sep;
	t_list	*last;

	if (check_prev(command, i, *cmds))
	{
		while (command[i] && (command[i] == '<' || command[i] == '>'))
			i++;
		last = ft_lstlast(*cmds);//전꺼 free?
		sep = ft_substr(command, start, i - start);
		check_sep(sep);
		last -> content = ft_strjoin(last -> content, sep);
	}
	else
	{
		while (command[i] && (command[i] == '<' || command[i] == '>'))
				i++;
		sep = ft_substr(command, start, i - start);
		check_sep(sep);
		add_list(sep, cmds);
	}
	return (i - start);
}

int	get_word(char *command, int i, t_list **cmds, int *flag)
{
	int	start;

	start = i;
	while (command[i] && is_not_sep(command[i]))
	{
		if (command[i] == '"' || command[i] == '\'')
			i = i + check_end(command, i, command[i]);
		i++;
	}
	add_list(ft_substr(command, start, i - start), cmds);
	*flag = 0;
	return (i);
}

int	get_operator(char *command, int i, t_list **cmds, int *flag)
{
	int	start;

	start = i;
	if (command[i] && (command[i] == '<' || command[i] == '>'))
	{
		start = i;
		if (*flag == 1)
			error_m(0);
		i += find_sep(command, start, i, cmds);
		*flag = 1;
	}
	if (command[i] == '|')
	{
		if (*flag == 1)
			error_m(0);
		add_list(ft_substr(command, i++, 1), cmds);
		*flag = 1;
	}
	return (i);
}

t_list	*split_command(char *command)
{
	t_list	*cmds;
	int		i;
	int		start;
	int		flag;

	cmds = 0;
	i = 0;
	start = -1;
	flag = 0;
	while (command[i])
	{
		if (is_not_sep(command[i]))
			i = get_word(command, i, &cmds, &flag);
		else
		{
			while (command[i] && command[i] == ' ')
				i++;
			if (command[i] && (command[i] == '<' || command[i] == '>' \
					|| command[i] == '|'))
				i = get_operator(command, i, &cmds, &flag);
		}
	}
	return (cmds);
}

void	check_error(t_list *list)
{
	int		flag;
	char	*c;

	flag = 0;
	c = list -> content;
	if (ft_strcmp(c, "|") || ft_strcmp(c, "<") || ft_strcmp(c, ">"))
		error_m(0);
	c = ft_lstlast(list)->content;
	while (*c)
	{
		if (*c == '<' || *c == '>')
			error_m(6);
		c++;
	}
}
///////////////////////////////////////////////////////////////
int	pipe_num(t_list	*list)
{
	t_list	*temp;
	int		num;

	temp = list;
	num = 0;
	while (temp)
	{
		if (ft_strcmp(temp->content, "|"))
			num++;
		temp = temp -> next;
	}
	return (num);
}

void	add_last(t_redirect **rd, t_redirect * new)
{
	t_redirect	*temp;

	if (new == NULL)
		return ;
	if (*rd == NULL)
		*rd = new;
	else
	{
		temp = *rd;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

int	check_if_pair(char	*content, char quotes)
{
	while (*content)
	{
		if (*content == quotes)
			return (1);
		content++;
	}
	return (0);
}

t_redirect	*malloc_redirect(int type, char *fd, char *file)
{
	t_redirect *new;

	new = malloc(sizeof(t_redirect));
	if (!new)
		//exit(1);
	new -> type = type;
	new -> fd = fd;
	new -> file = file;
	new -> next = 0;
	return (new);
}

int	check_type(char	*content)
{
	char	quotes;

	while (*content)
	{
		if (*content == '"' || *content == '\'')
		{	
			quotes = *content;
			content++;
			if (*content && check_if_pair(content, quotes))
				return (2);
		}
		content++;
	}
	return (1);
}

void	check_input(t_info *info, char *content, t_command *command, char *file)
{
	int			i;
	char		*fd;
	int			n;
	int			type;
	t_redirect	*new;

	i = 0;
	n = 0;
	while (ft_isdigit(content[i]))
		i++;
	if (i != 0)
		fd = ft_substr(content, 0, i);
	else
		fd = 0;
	while (content[i++] == '<')
		n++;
	if (n == 1)
		type = 0;
	else
	{
		info->heredoc_num++;
		type = check_type(content);
	}
	new = malloc_redirect(type, fd, file);
	add_last(&(command -> input), new);
}

void	check_output(t_info *info, char *content, t_command *command,char *file)
{
	int			i;
	char		*fd;
	int			n;
	int			type;
	t_redirect	*new;

	i = 0;
	n = 0;
	while (ft_isdigit(content[i]))
		i++;
	if (i != 0)
		fd = ft_substr(content, 0, i);
	else
		fd = 0;
	while (content[i++] == '>')
		n++;
	if (n == 1)
		type = 0;
	else
	{
		info->heredoc_num++;
		type = 1;
	}
	new = malloc_redirect(type, fd, file);
	add_last(&(command -> output), new);
}

void	init_command(t_command *command, int num)
{
	command -> input = 0;
	command -> output = 0;
	if (num != 0)
	{
		command ->command =(char **)malloc(sizeof(char *) * (num + 1));
		if (!command->command)
			exit(1);
			//널가드 
		(command ->command)[num] = 0;
	}
	else
		command -> command = 0;
}

extern int exit_status;

void	join_env_2(char **line, char *env_value, int start, int end)
{
	char	*temp;
	char	*head;
	char	*tail;

	temp = *line;
	if (start == 0)
		head = NULL;
	else
		head = ft_substr(temp, 0, start);
	if (end == (int)ft_strlen(temp))
		tail = NULL;
	else
		tail = ft_substr(temp, end, ft_strlen(temp) - end);
	free(temp);
	temp = ft_strjoin(head, env_value);
	*line = ft_strjoin(temp, tail);
	free(temp);
}

void	expand_env_inner(char **line, t_env *env_lst, int *i)
{
	char	*env_key;
	char	*env_value;
	t_env	*lst;
	int		j;

	if ((*line)[*i] == '$' && (*line)[*i + 1] == '?')
	{
		env_value = ft_itoa(exit_status);
		join_env_2(line, env_value, *i, *i + 2);
		*i += ft_strlen(env_value);
	}
	else if ((*line)[*i] == '$')
	{
		j = 1;
		while ((*line)[*i + j] && ft_inset((*line)[*i + j], " $") == 0)
			j++;
		if (j == 1)
		{
			++*i;
			return ;
		}
		env_key = ft_substr(&(*line)[*i + 1], 0, j - 1);
		lst = get_lst_by_key(env_lst, env_key);
		if (lst == NULL)
			env_value = "";
		else
			env_value = lst->value;
		join_env_2(line, env_value, *i, *i + j);
		*i += ft_strlen(env_value);
	}
	else
			++*i;
}


void	expand_env_2(char **line, t_env *env_lst)
{
	int		i;
	// int		j;
	// char	*env_key;
	// char	*env_value;
	// t_env	*lst;

	i = 0;
	if (*line == NULL)
		return ;
	while ((*line)[i])
	{
		if ((*line)[i] == '"')
			while (i <= i + check_end(*line, i, '"'))
				expand_env_inner(line, env_lst, &i);
		else if ((*line)[i] == '\'')
			i = i + check_end(*line, i, '\'');
		else
			expand_env_inner(line, env_lst, &i);
		// if ((*line)[i] == '$' && (*line)[i + 1] == '?')
		// {
		// 	env_value = ft_itoa(exit_status);
		// 	join_env(line, env_value, i, i + 2);
		// 	i += ft_strlen(env_value);
		// }
		// else if ((*line)[i] == '$')
		// {
		// 	j = 1;
		// 	while ((*line)[i + j] && ft_inset((*line)[i + j], " $") == 0)
		// 		j++;
		// 	if (j == 1)
		// 	{
		// 		++i;
		// 		continue ;
		// 	}
		// 	env_key = ft_substr(&(*line)[i + 1], 0, j - 1);
		// 	lst = get_lst_by_key(env_lst, env_key);
		// 	if (lst == NULL)
		// 		env_value = "";
		// 	else
		// 		env_value = lst->value;
		// 	join_env(line, env_value, i, i + j);
		// 	i += ft_strlen(env_value);
		// }
		// else
		// 	++i;
	}
}

char	*check_cmd(char	*content, t_env *env_lst)
{
	char	*temp;
	int		i;
	char	quotes;

	if (ft_strchr(content, '$'))
		expand_env_2(&content, env_lst);
	temp = malloc(sizeof(char) * ft_strlen(content));
	i = 0;
	while (content[i])
	{
		if (content[i] == '"' || content[i] == '\'')
		{
			quotes = content[i];
			if (check_if_pair(content + i, quotes))
			{
				temp[i] = quotes;
				i++;
				while (1)
				{
					if (content[i] == quotes)
					{
						temp[i] = content[i];
						i++;
						break ;
					}
					i++;
				}
			}
		}
		else
		{
			temp[i] = content[i];
			i++;
		}		
	}
	temp[i] = 0;
	return (temp);
}

int	check_word_num(t_list *list)
{
	t_list	*temp;
	int		len;
	char	*content;
	int		num;

	num = 0;
	temp = list;
	while (temp && !ft_strcmp(temp->content, "|"))
	{
		content = temp -> content;
		len = ft_strlen(content);
		if ((content[len - 1] == '<' || content[len - 1] == '>'))
			temp = temp -> next;
		else
			num++;
		temp = temp -> next;
	}
	return (num);
}

t_list	*put_command(t_info *info, t_command *command, t_list *list, t_env *env_lst)
{
	int		len;
	char	*content;
	char	*file;
	int		num;
	int		j;

	j = 0;
	num = check_word_num(list);
	init_command(command, num);
	if (command->input == 0)
		ft_printf("1\n");
	while (list && !ft_strcmp(list->content, "|"))
	{
		content = list -> content;
		len = ft_strlen(content);
		if (content[len - 1] == '<')
		{
			list = list -> next;
			file = check_cmd(list -> content, env_lst);
			check_input(info, content, command, file);
		}
		else if (content[len - 1] == '>')
		{
			list = list -> next;
			file = check_cmd(list -> content, env_lst);
			check_output(info, content, command, file);
		}
		else
		{
			(command->command)[j++] = ft_strdup(check_cmd(content, env_lst));
		}
		list = list -> next;
	}
	return (list);
}

t_info	*parse_command(char *command, t_env *env_lst)
{
	// 파싱 구현
	// syntax error NULL 반환 
	t_list	*list;
	t_info	*info;
	int		i;

	i = 0;
	list = split_command(command);
	//list가 null이면 info가 null
	check_error(list);
	info = malloc(sizeof(t_info));
	info->heredoc_num = 0;
	info->process_num = pipe_num(list) + 1;
	info->commands = (t_command *)malloc(sizeof(t_command) * info->process_num);
	while (i < info->process_num)
	{
		list = put_command(info, &(info->commands[i]), list, env_lst);
		i++;
	}
	return (info);
}

void    print_info(t_info *info)
{
    ft_printf("process_num = %d\n", info->process_num);
    ft_printf("heredoc_num = %d\n", info->heredoc_num);
    int i = 0;
    int j;
    t_command *command;
    t_redirect *input;
    t_redirect *output;
    while (i < info->process_num)
    {
        ft_printf("commands %d\n", i);
        j = 0;
        command = &(info->commands[i]);
        input = command->input;
        output = command->output;
        while (command->command[j])
        {
            ft_printf("%s\n", command->command[j]);
            j++;
        }
        while (input)
        {
            ft_printf("input\n");
            ft_printf("type: %d\n", input->type);
            ft_printf("type: %s\n", input->fd);
            ft_printf("type: %s\n", input->file);
            input = input->next;
        }
        while (output)
        {
            ft_printf("input\n");
            ft_printf("type: %d\n", output->type);
            ft_printf("type: %s\n", output->fd);
            ft_printf("type: %s\n", output->file);
            input = input->next;
        }
        ++i;
    }
}

int	main(int argc, char *argv[], char **env)
{
	t_env		*env_lst;
	char		*command;
	char		*add;
	t_info		*info;
	t_process	*process;
	char		*temp;

	init(argc, argv, env, &env_lst);
	while (1)
	{
		command = read_command();
		if (command == NULL)
			continue ;
		if (command[ft_strlen(command) - 1] == '|' && command[ft_strlen(command) - 2] != '|')
		{
			add = ft_strdup(" |");
			while (add[ft_strlen(add) - 1] == '|' && add[ft_strlen(add) - 2] != '|')
			{
				free(add);
				add = readline("> ");
				temp = command;
				command = ft_strjoin(command, add);
				free(temp);
			}
			free(add);
		}
		if (ft_strncmp(command, "", 1) == 0) //나중에 parse에서 처리 - 아무것도 없으면 NULL로
			continue ;
		info = parse_command(command, env_lst);
		if (info == NULL)
			continue ;
		print_info(info);
		if (create_heredoc_temp(info, env_lst) == 0)
			continue ;
		if (info->process_num == 1)
		{
			if (exec_single_builtin(info, &env_lst))
			{
				unlink_heredocs(info);
				exit_status = 0;
				continue ;
			}
		}
		process = (t_process *)malloc(sizeof(t_process) * info->process_num);
		create_pipe(process, info->process_num);
		fork_and_execute(process, info, &env_lst);
		wait_all_child(info->process_num, process);
		unlink_heredocs(info);
		free(command);
	}
}
