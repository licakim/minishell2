/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:18:31 by jihyeole          #+#    #+#             */
/*   Updated: 2022/12/09 20:03:02 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sp;
	size_t			i;

	sp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*(sp + i) == (unsigned char) c)
			return (sp + i);
		i++;
	}
	return (NULL);
}
