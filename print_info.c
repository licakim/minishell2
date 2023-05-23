/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:37:19 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/21 12:47:43 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_info(t_info *info)
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
