/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:19:44 by jihyeole          #+#    #+#             */
/*   Updated: 2022/11/30 14:38:54 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dp;
	unsigned char	*sp;

	dp = (unsigned char *)dst;
	sp = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	while (n > 0)
	{
		n--;
		*(dp + n) = (unsigned char) *(sp + n);
	}
	return (dst);
}
