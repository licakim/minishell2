/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:00:03 by jihyeole          #+#    #+#             */
/*   Updated: 2023/03/10 18:39:24 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_char(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

static int	print_str(va_list ap)
{
	char	*s;
	int		len;

	len = 0;
	s = va_arg(ap, char *);
	if (s == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		len += 6;
	}
	else
	{
		while (*s)
		{
			if (write(1, s, 1) == -1)
				return (-1);
			len++;
			s++;
		}
	}
	return (len);
}

static int	print_pointer(va_list ap)
{
	void			*p;
	unsigned long	num;
	int				len;

	p = va_arg(ap, void *);
	num = (unsigned long)p;
	len = write(1, "0x", 2);
	if (len == -1)
		return (-1);
	len = print_hex_low(num, 1);
	if (len == -1)
		return (-1);
	len = 2;
	if (num == 0)
		len++;
	while (num > 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

static int	print_arg(va_list ap, char c)
{
	if (c == 'c')
		return (print_char(ap));
	if (c == 's')
		return (print_str(ap));
	if (c == '%')
	{
		if (write(1, "%%", 1) == -1)
			return (-1);
		return (1);
	}
	if (c == 'd' || c == 'i')
		return (print_decimal(ap, 1));
	if (c == 'u')
		return (print_decimal(ap, 0));
	if (c == 'x')
		return (puthex(ap, 0));
	if (c == 'X')
		return (puthex(ap, 1));
	if (c == 'p')
		return (print_pointer(ap));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	int				len;
	int				arg_len;

	va_start(ap, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			arg_len = print_arg(ap, *(format + 1));
			if (arg_len == -1)
				return (-1);
			len += arg_len;
			format += 2;
		}
		else
		{
			if (write(1, format++, 1) == -1)
				return (-1);
			len++;
		}
	}
	va_end(ap);
	return (len);
}
