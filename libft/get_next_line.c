/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:22:22 by jihyeole          #+#    #+#             */
/*   Updated: 2023/02/16 18:48:09 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*del_node(t_glist *node, t_glist **head)
{
	if (node->content)
	{
		free(node->content);
		node->content = NULL;
	}
	if (node == *head)
		*head = node->next;
	else
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	free(node);
	node = 0;
	return (NULL);
}

static t_glist	*find_node(t_glist **head, int fd)
{
	t_glist	*node;

	node = *head;
	while (node && node->fd != fd)
		node = node->next;
	if (node)
		return (node);
	node = (t_glist *)malloc(sizeof(t_glist));
	if (!node)
		return (NULL);
	node->fd = fd;
	node->content = ft_strndup("", 0);
	if (!node->content)
		return (del(node));
	node->prev = NULL;
	if (*head)
	{
		node->next = *head;
		(*head)->prev = node;
	}
	else
		node->next = NULL;
	*head = node;
	return (node);
}

static int	read_process(t_glist *node)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	read_size;
	size_t	idx;

	while (1)
	{
		idx = 0;
		while (*(node->content + idx))
		{
			if (*(node->content + idx) == '\n')
				return (1);
			idx++;
		}
		read_size = read(node->fd, buf, BUFFER_SIZE);
		if (read_size < 0)
			return (0);
		if (read_size == 0)
			return (1);
		buf[read_size] = 0;
		node->content = gnl_strjoin(node->content, buf);
		if (!node->content)
			return (0);
	}
}

static char	*get_line(t_glist *node)
{
	size_t	l_len;
	size_t	t_len;
	char	*line;
	char	*temp;

	if (!*(node->content))
		return (NULL);
	l_len = 0;
	while (*(node->content + l_len) != '\n' && *(node->content + l_len))
		l_len++;
	if (*(node->content + l_len) == '\n')
		l_len++;
	line = ft_strndup(node->content, l_len);
	if (!line)
		return (NULL);
	t_len = 0;
	while (*(node->content + l_len + t_len))
		t_len++;
	temp = ft_strndup(node->content + l_len, t_len);
	if (!temp)
		return (del(line));
	free(node->content);
	node->content = temp;
	return (line);
}

char	*get_next_line(int fd)
{
	static t_glist	*head;
	t_glist			*node;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = find_node(&head, fd);
	if (!node)
		return (NULL);
	if (!read_process(node))
		return (del_node(node, &head));
	line = get_line(node);
	if (!line)
		return (del_node(node, &head));
	return (line);
}
