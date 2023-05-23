/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:22:17 by jihyeole          #+#    #+#             */
/*   Updated: 2023/02/16 18:46:40 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*del(void *a)
{
	free(a);
	a = 0;
	return (NULL);
}

int	have_newline(const char *buf)
{
	if (buf == 0)
		return (0);
	while (*buf)
	{
		if (*buf == '\n')
			return (1);
		buf++;
	}
	return (0);
}

void	ft_strncpy(char *dest, char *src, size_t n)
{
	while (n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
}

char	*ft_strndup(char *s, size_t n)
{
	char	*str;

	str = (char *)malloc(n + 1);
	if (!str)
		return (NULL);
	ft_strncpy(str, s, n);
	*(str + n) = 0;
	return (str);
}

char	*gnl_strjoin(char *temp, char *buf)
{
	size_t	temp_len;
	size_t	buf_len;
	char	*s;

	temp_len = 0;
	while (*(temp + temp_len))
		temp_len++;
	buf_len = 0;
	while (*(buf + buf_len))
		buf_len++;
	s = (char *)malloc(temp_len + buf_len + 1);
	if (!s)
	{
		if (temp)
			del(temp);
		return (NULL);
	}
	ft_strncpy(s, temp, temp_len);
	ft_strncpy(s + temp_len, buf, buf_len);
	s[temp_len + buf_len] = 0;
	if (temp)
		del(temp);
	return (s);
}
