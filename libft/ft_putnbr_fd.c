/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:48:13 by jihyeole          #+#    #+#             */
/*   Updated: 2022/12/06 20:20:21 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_nbr(long num, int fd)
{
	char	nbr;

	if (num / 10 != 0)
		print_nbr(num / 10, fd);
	nbr = '0' + num % 10;
	write(fd, &nbr, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		print_nbr(num * -1, fd);
	}
	else if (num == 0)
		write(fd, "0", 1);
	else
		print_nbr(num, fd);
}
