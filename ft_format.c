/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaherre <leaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:58:17 by leaherre          #+#    #+#             */
/*   Updated: 2025/10/31 15:58:17 by leaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	int	res;
	int	count;

	count = 0;
	res = write (1, &c, 1);
	if (res == -1)
		return (-1);
	count = res + count;
	return (count);
}

int	ft_print_unsigned(unsigned int n)
{
	char	x;
	int		len;

	len = 0;
	if (n > 9)
	{
		len += ft_print_unsigned(n / 10);
		len += ft_print_unsigned(n % 10);
	}
	else
	{
		x = n + '0';
		len += write(1, &x, 1);
	}
	return (len);
}

int	ft_printptr(unsigned long long n)
{
	int	count;
	int	res;

	count = 0;
	if (n == 0)
		return (write(1, "(nil)", 5));
	res = write (1, "0x", 2);
	if (res == -1)
		return (-1);
	count = count + res;
	res = ft_hex_base(n);
	if (res == -1)
		return (-1);
	count = count + res;
	return (count);
}

int	ft_hex_base(unsigned long long n)
{
	int	remainder;
	int	count;
	int	res;

	count = 0;
	remainder = n % 16;
	if ((n / 16) > 0)
	{
		res = ft_hex_base (n / 16);
		if (res == -1)
			return (-1);
		count = count + res;
	}
	if (remainder > 9)
		res = ft_putchar(remainder + 'a' - 10);
	else
		res = ft_putchar(remainder + '0');
	if (res == -1)
		return (-1);
	count = count + res;
	return (count);
}

int	ft_hex_base_up(unsigned long long n)
{
	int	remainder;
	int	count;
	int	res;

	count = 0;
	remainder = n % 16;
	if ((n / 16) > 0)
	{
		res = ft_hex_base_up (n / 16);
		if (res == -1)
			return (-1);
		count = count + res;
	}
	if (remainder > 9)
		res = ft_putchar(remainder + 'A' - 10);
	else
		res = ft_putchar(remainder + '0');
	if (res == -1)
		return (-1);
	count = count + res;
	return (count);
}
