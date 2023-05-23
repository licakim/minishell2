/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:26:44 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/15 16:28:46 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	i;

	if (s1 == NULL)
		return (NULL);
	p = (char *)malloc(ft_strlen(s1) + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i <= ft_strlen(s1))
	{
		p[i] = s1[i];
		i++;
	}
	return (p);
}
