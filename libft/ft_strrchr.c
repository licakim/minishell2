/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:45:14 by jihyeole          #+#    #+#             */
/*   Updated: 2022/12/02 19:09:08 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	idx;

	idx = 0;
	while (*(s + idx))
		idx++;
	while (*(s + idx) != (char) c)
	{
		if (idx == 0)
			return (NULL);
		idx--;
	}
	return ((char *)s + idx);
}
