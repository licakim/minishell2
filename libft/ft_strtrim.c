/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:34:57 by jihyeole          #+#    #+#             */
/*   Updated: 2023/03/08 20:15:42 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	start;
	size_t	end;

	if (s1 == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_inset(*(s1 + start), set) && start < ft_strlen(s1))
		start++;
	if (start == ft_strlen(s1))
		end = start;
	else
		while (ft_inset(*(s1 + end), set))
			end--;
	p = ft_substr(s1, start, end - start + 1);
	return (p);
}
