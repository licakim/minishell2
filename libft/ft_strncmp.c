/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:06:40 by jihyeole          #+#    #+#             */
/*   Updated: 2022/11/30 11:53:54 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			idx;
	unsigned char	*c1;
	unsigned char	*c2;

	idx = 0;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (*(c1 + idx) == *(c2 + idx))
	{
		if (idx == (n - 1) || *(c1 + idx) == 0)
			return (0);
		idx++;
	}
	if (*(c1 + idx) > *(c2 + idx))
		return (1);
	else
		return (-1);
}
