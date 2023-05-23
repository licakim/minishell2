/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:30:42 by jihyeole          #+#    #+#             */
/*   Updated: 2022/12/06 17:26:55 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	idx;

	str = (char *)malloc(ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	idx = 0;
	while (*s != 0)
	{
		*(str + idx) = f(idx, *s);
		idx++;
		s++;
	}
	*(str + idx) = 0;
	return (str);
}
