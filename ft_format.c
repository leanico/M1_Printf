
int ft_print_char(int c)
{
	int res;
	int count;

	count = 0;
	res = write (1, &c, 1);
	if (res == -1) 
		return (-1); 
	count = res + count;
	return (count);
}

int ft_print_unsigned(unsigned int n)
{
	int res;
	int count;
	char *s;
	int len;

	count = 0;
	len = ft_strlen (s);
	res = write(1, s, len);
	if (res == -1) 
		return (-1); 
	count = res + count;
	return (count);	
}

int	ft_putstr(char *s)
{
	int	res;
	int	count;

	count = 0;
	if (s == NULL)
		return ;
	res = write (1, s, ft_strlen(s));
	if (res == -1) 
        return (-1);
	count = res + count;
	return (count);
}

int ft_printptr(unsigned long long n)
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

int ft_print_nbr(int n)
{

}

// Es el tipo de dato más seguro para trabajar con la dirección de memoria (%p), 
// ya que garantiza que el número de 64 bits de la dirección no se desborde, manteniendo la integridad de la conversión. 
// También funcionará perfectamente para unsigned int (%x y %X).

int ft_hex_base(unsigned long long n)
{
    int remainder;
    int count;
    int res;

    count = 0;
	remainder = n % 16;
	if ((n / 16) > 0)
	{
		res = ft_hez_base (n / 16);
		if (res == -1)
			return (-1);
		count = count + res;
	}
	if(remainder > 9)
		res = ft_putchar(n % 16 + 'a' - 10)
	else
		res = ft_putchar(n % 16 + '0')
	if (res == -1)
		return (-1);
	count = count + res;
    return (count);
}




ft_putnbr_base(unsigned long n, char *base) → función común para conversión