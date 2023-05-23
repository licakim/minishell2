/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:34:57 by jihyeole          #+#    #+#             */
/*   Updated: 2022/11/29 18:19:45 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*chp;

	chp = (unsigned char *)b;
	while (len > 0)
	{
		len--;
		*(chp + len) = (unsigned char)c;
	}
	return (b);
}
