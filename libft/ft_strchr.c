/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:47:51 by jihyeole          #+#    #+#             */
/*   Updated: 2022/12/02 18:53:57 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	idx;

	idx = 0;
	while (*(s + idx) != (char) c)
	{
		if (*(s + idx) == '\0')
			return (NULL);
		idx++;
	}
	return ((char *)s + idx);
}
