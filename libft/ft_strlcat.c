/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:32:21 by jihyeole          #+#    #+#             */
/*   Updated: 2022/12/09 21:52:19 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;

	if ((!dst || !src) && dstsize == 0)
	{
		return (0);
	}
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen >= dstsize)
		return (srclen + dstsize);
	while (*dst != '\0')
	{
		dst++;
		dstsize--;
	}
	while (*src != '\0' && dstsize > 1)
	{
		*dst = *src;
		dst++;
		src++;
		dstsize--;
	}
	*dst = '\0';
	return (dstlen + srclen);
}
