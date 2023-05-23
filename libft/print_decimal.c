/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:10:52 by jihyeole          #+#    #+#             */
/*   Updated: 2023/03/10 18:40:44 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	print_nbr(long num, int fd)
{
	char	nbr;
	ssize_t	n;

	if (num / 10 != 0)
	{
		n = print_nbr(num / 10, fd);
		if (n == -1)
			return (-1);
	}
	nbr = '0' + num % 10;
	n = write(fd, &nbr, 1);
	return (n);
}

static int	my_putnbr_fd(long num, int fd)
{
	ssize_t	n;

	if (num == 0)
	{
		n = write(fd, "0", 1);
		if (n == -1)
			return (-1);
		return (1);
	}
	if (num < 0)
	{
		n = write(fd, "-", 1);
		if (n == -1)
			return (-1);
		num *= -1;
	}
	n = print_nbr(num, fd);
	if (n == -1)
		return (-1);
	return (1);
}

int	print_decimal(va_list ap, int issigned)
{
	long	num;
	int		len;

	num = 0;
	if (issigned == 1)
		num = (long) va_arg(ap, int);
	else if (issigned == 0)
		num = (long) va_arg(ap, unsigned int);
	len = my_putnbr_fd(num, 1);
	if (len == -1)
		return (-1);
	len = 0;
	if (num == 0)
		return (1);
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
