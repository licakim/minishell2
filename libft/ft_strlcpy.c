/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:29:29 by jihyeole          #+#    #+#             */
/*   Updated: 2022/11/29 18:20:04 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	cnt;

	cnt = 0;
	while (dstsize > 1 && *src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
		cnt++;
		dstsize--;
	}
	while (*src != '\0')
	{
		src++;
		cnt++;
	}
	if (dstsize != 0)
		*dst = '\0';
	return (cnt);
}
