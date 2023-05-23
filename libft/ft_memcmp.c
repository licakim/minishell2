/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:28:48 by jihyeole          #+#    #+#             */
/*   Updated: 2022/11/29 18:19:30 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*sp1;
	unsigned char	*sp2;
	size_t			idx;

	sp1 = (unsigned char *)s1;
	sp2 = (unsigned char *)s2;
	idx = 0;
	if (n == 0)
		return (0);
	while (*(sp1 + idx) == *(sp2 + idx))
	{
		idx++;
		if (idx == n)
			return (0);
	}
	return (*(sp1 + idx) - *(sp2 + idx));
}
