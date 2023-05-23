/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:02:26 by jihyeole          #+#    #+#             */
/*   Updated: 2022/11/30 14:41:50 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dp;
	unsigned char	*sp;
	size_t			i;

	dp = (unsigned char *)dst;
	sp = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (dp > sp)
	{
		while (len-- > 0)
		{
			*(dp + len) = (unsigned char) *(sp + len);
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			*(dp + i) = (unsigned char) *(sp + i);
			i++;
		}
	}
	return (dst);
}
