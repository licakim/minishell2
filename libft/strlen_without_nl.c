/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_without_nl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:37:33 by jihyeole          #+#    #+#             */
/*   Updated: 2023/03/08 20:30:57 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	strlen_without_nl(const char *s)
{
	size_t	cnt;

	cnt = 0;
	if (!s)
		return (0);
	while (*(s + cnt) && *(s + cnt) != '\n')
		cnt++;
	return (cnt);
}
