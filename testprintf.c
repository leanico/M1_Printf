#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include <limits.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int	ft_printf(char const *format, ...);
static int	ft_putnbr(int n);
static int	ft_putchar(char c);
static size_t	ft_strlen(const char *str);
static int	ft_print_char(int c);
// static int	ft_print_unsigned(unsigned int n);
static int	ft_putstr(char *s);
static int	ft_printptr(unsigned long long n);
static int	ft_hex_base(unsigned long long n);
static int	ft_hex_base_up(unsigned long long n);
// static char	*ft_uitoa(unsigned int n);
// static size_t	ft_strlen2(unsigned int n);

int	ft_printf(char const *format, ...)
{
	va_list			list;
	int				count;
	int				res;
	int				c;
	int				n;
	unsigned int	n2;
	void			*p;
	char			*s;

	count = 0;
	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				format++;
				c = va_arg(list, int);
				res = ft_print_char(c);
				if (res == -1)
					return (-1);
				count = count + res;
			}
			else if (*format == '%')
			{
				format++;
				res = write (1, "%", 1);
				if (res == -1)
					return (-1);
				count = res + count;
			}
			else if (*format == 's')
			{
				format++;
				s = va_arg(list, char *);
				res = ft_putstr(s);
				if (res == -1)
					return (-1);
				count = count + res;
			}
			else if (*format == 'd' || *format == 'i')
			{
				format++;
				n = va_arg(list, int);
				res = ft_putnbr(n);
				if (res == -1)
					return (-1);
				count = count + res;
			}
			else if (*format == 'u')
			{
				format++;
				n2 = va_arg(list, unsigned int);
				res = ft_putnbr(n2);
				if (res == -1)
					return (-1);
				count = count + res;
			}
			else if (*format == 'p')
			{
				format++;
				p = va_arg(list, void *);
				res = ft_printptr((unsigned long long)p);
				if (res == -1)
					return (-1);
				count = count + res;
			}
			else if (*format == 'x')
			{
				format++;
				n2 = va_arg(list, unsigned int);
				res = ft_hex_base(n2);
				if (res == -1)
					return (-1);
				count = count + res;
			}
			else if (*format == 'X')
			{
				format++;
				n2 = va_arg(list, unsigned int);
				res = ft_hex_base_up(n2);
				if (res == -1)
					return (-1);
				count = count + res;
			}
			else
			{
				format++;
				res = write(1, format, 1);
				if (res == -1)
					return (-1);
				count = count + res;
				format++;
			}
		}
		else
		{
			res = write(1, format, 1);
			if (res == -1)
				return (-1);
			count = count + res;
			format++;
		}
}
	va_end(list);
	return (count);
}

static int	ft_print_char(int c)
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

// static int	ft_print_unsigned(unsigned int n)
// {
// 	int		res;
// 	int		count;
// 	char	*s;
// 	int		len;

// 	count = 0;
// 	s = ft_uitoa(n);
// 	if (s == NULL)
// 		return(-1);
// 	len = ft_strlen (s);
// 	res = write(1, s, len);
// 	if (res == -1)
// 	{
// 		free(s);
// 		return (-1);
// 	}
// 	free(s);
// 	count = res + count;
// 	return (count);
// }

static int	ft_putstr(char *s)
{
	int	res;
	int	count;

	count = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	res = write (1, s, ft_strlen(s));
	if (res == -1)
		return (-1);
	count = res + count;
	return (count);
}

static int	ft_printptr(unsigned long long n)
{
	int	count;
	int	res;

	count = 0;
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

static int	ft_hex_base(unsigned long long n)
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

static int	ft_hex_base_up(unsigned long long n)
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

static int	ft_putnbr(int n)
{
	long	nb;
	int		count;
	int		res;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		res = write(1, "-", 1);
		if (res == -1)
			return (-1);
		count = count + res;
		nb = -nb;
	}
	if (nb >= 10)
	{
		res = ft_putnbr(nb / 10);
		if (res == -1)
			return (-1);
		count = count + res;
	}
	res = ft_putchar(nb % 10 + '0');
	if (res == -1)
		return (-1);
	count = count + res;
	return (count);
}

static int	ft_putchar(char c)
{
	int	res;

	res = write(1, &c, 1);
	if (res == -1)
		return (-1);
	return (1);
}

static size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str [i] != '\0')
	{
		i++;
	}
	return (i);
}

// static size_t	ft_strlen2(unsigned int n)
// {
// 	unsigned int	i;

// 	i = 0;
// 	while (n != 0)
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// static char	*ft_uitoa(unsigned int n)
// {
// 	int		len;
// 	long	copy;
// 	char	*str;
// 	int		i;

// 	copy = n;
// 	len = ft_strlen2(n);
// 	str = (char *) malloc(len + 1);
// 	if (str == NULL)
// 		return (NULL);
// 	str[len] = '\0';
// 	i = len - 1;
// 	if (copy == 0)
// 		str[0] = '0';
// 	while (copy > 0)
// 	{
// 		str[i] = ((copy % 10) + '0');
// 		copy = copy / 10;
// 		i--;
// 	}
// 	return (str);
// }

int	main(void)
{
	int ret1;
	int ret2;
	char c = 'A';
	char *str = "Hola, printf!";
	int num = -42;
	unsigned int unum = 424242;
	void *ptr = &num;

	printf("=== TEST DE ft_printf ===\n");

	// %c
	ret1 = ft_printf("Mi char: %c \n", c);
	ret2 = printf("Oficial:  %c \n", c);

	// // %s
	ret1 = ft_printf("Mi string: %s\n", str);
	ret2 = printf("Oficial:   %s\n\n", str);

	// // %d y %i
	ret1 = ft_printf("Mi decimal: %d\n", num);
	ret2 = printf("Oficial:    %d\n\n", num);

	ret1 = ft_printf("Mi entero con %%i: %i\n", num);
	ret2 = printf("Oficial con %%i:    %i\n\n", num);

	// // %u
	ret1 = ft_printf("Mi unsigned: %u\n", unum);
	ret2 = printf("Oficial:     %u\n\n", unum);

	// // %x
	ret1 = ft_printf("Mi hexa minúscula: %x\n", unum);
	ret2 = printf("Oficial:           %x\n\n", unum);

	// // %X
	ret1 = ft_printf("Mi hexa MAYÚSCULA: %X\n", unum);
	ret2 = printf("Oficial:           %X\n\n", unum);

	// // // %p
	ret1 = ft_printf("Mi puntero: %p\n", ptr);
	ret2 = printf("Oficial:    %p\n\n", ptr);

	// // // %%
	ret1 = ft_printf("Porcentaje: %%\n");
	ret2 = printf("Oficial:    %%\n\n");

	ft_printf("Mis retornos: ft_printf=%d | printf=%d\n", ret1, ret2);

	return (0);
}
