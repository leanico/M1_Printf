/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaherre <leaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:34:15 by leaherre          #+#    #+#             */
/*   Updated: 2025/11/08 17:34:15 by leaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(char const *format, ...);
int		ft_putnbr(int n);
int		ft_putchar(char c);
int		ft_print_char(int c);
int		ft_print_unsigned(unsigned int n);
int		ft_putstr(char *s);
int		ft_printptr(unsigned long long n);
int		ft_hex_base(unsigned long long n);
int		ft_hex_base_up(unsigned long long n);
size_t	ft_strlen(const char *str);
int		ft_case_c(va_list list);
int		ft_case_s(va_list list);
int		ft_case_di(va_list list);
int		ft_case_u(va_list list);
int		ft_case_p(va_list list);
int		ft_case_xup(va_list list);
int		ft_case_xlow(va_list list);
int		ft_handleformat(char const *format, va_list list);

#endif
