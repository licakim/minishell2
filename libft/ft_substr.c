/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:53:50 by jihyeole          #+#    #+#             */
/*   Updated: 2022/12/07 21:56:13 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*p;

	slen = ft_strlen(s);
	if (start >= slen)
	{
		p = (char *)malloc(1);
		if (p == NULL)
			return (NULL);
		*p = 0;
		return (p);
	}
	if (len > slen - start)
		len = slen - start;
	p = (char *)malloc(len + 1);
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, s + start, len + 1);
	return (p);
}
