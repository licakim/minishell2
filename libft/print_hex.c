/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:15:03 by jihyeole          #+#    #+#             */
/*   Updated: 2023/03/10 18:41:20 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	my_strlcpy(char *dst, const char *src, size_t dstsize)
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

int	print_hex_low(unsigned long n, int fd)
{
	char	hex[17];

	my_strlcpy(hex, "0123456789abcdef", 17);
	if (n / 16 != 0)
	{
		if (print_hex_low(n / 16, fd) == -1)
			return (-1);
	}
	return (write(fd, &hex[n % 16], 1));
}

static int	print_hex_up(unsigned int n, int fd)
{
	char	hex[17];

	my_strlcpy(hex, "0123456789ABCDEF", 17);
	if (n / 16 != 0)
	{
		if (print_hex_up(n / 16, fd) == -1)
			return (-1);
	}
	return (write(fd, &hex[n % 16], 1));
}

int	puthex(va_list ap, int isup)
{
	unsigned int	num;
	int				len;

	num = va_arg(ap, unsigned int);
	if (isup == 0)
		len = print_hex_low(num, 1);
	if (isup == 1)
		len = print_hex_up(num, 1);
	if (len == -1)
		return (-1);
	len = 0;
	if (num == 0)
		len++;
	while (num > 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}
