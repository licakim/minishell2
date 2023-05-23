/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:11:33 by jihyeole          #+#    #+#             */
/*   Updated: 2022/12/07 21:50:37 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_len(int num)
{
	int	len;

	if (num == 0)
		return (1);
	if (num == -2147483648)
		return (11);
	len = 0;
	if (num < 0)
	{
		len++;
		num *= -1;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static void	ptoa(char *s, long long num, int len)
{
	*(s + len) = 0;
	len--;
	while (num > 0)
	{
		*(s + len) = num % 10 + '0';
		len--;
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	long long	num;
	char		*str;
	int			len;

	len = cnt_len(n);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	num = n;
	if (num == 0)
	{
		*str = '0';
		*(str + 1) = 0;
	}
	else if (num < 0)
	{
		num *= -1;
		*str = '-';
		ptoa(str + 1, num, len - 1);
	}
	else
		ptoa(str, num, len);
	return (str);
}
