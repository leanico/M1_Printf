/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaherre <leaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:58:17 by leaherre          #+#    #+#             */
/*   Updated: 2025/10/31 15:58:17 by leaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handleformat(char const *format, va_list list)
{
	int	count;

	count = 0;
	if (*format == 'c')
		count += ft_case_c(list);
	else if (*format == '%')
		count += write(1, "%", 1);
	else if (*format == 's')
		count += ft_case_s(list);
	else if (*format == 'd' || *format == 'i')
		count += ft_case_di(list);
	else if (*format == 'u')
		count += ft_case_u(list);
	else if (*format == 'p')
		count += ft_case_p(list);
	else if (*format == 'x')
		count += ft_case_xlow(list);
	else if (*format == 'X')
		count += ft_case_xup(list);
	else
		return (0);
	if (count == -1)
		return (-1);
	return (count);
}

int	ft_printf(char const *format, ...)
{
	va_list			list;
	int				count;

	count = 0;
	va_start(list, format);
	if (!format)
	{
		va_end(list);
		return (-1);
	}
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_handleformat(format, list);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(list);
	return (count);
}
