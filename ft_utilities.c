

static int	ft_putnbr(int n) // chequear de dividirlo en 2
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

static int ft_putchar(char c)
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
