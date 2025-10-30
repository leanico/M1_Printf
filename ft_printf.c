
int	ft_printf(char const *, ...)
{
	va_list	list;
	int	count;
	int	res;
	int	c;
	int n;
	unsigned int n2;


	count  = 0;

	va_start(list, format);

	while (*format) // *format != '\0'
	{
	if(*format == '%') 
	{
	format++; // Avanzamos al especificador para que ya nos diga que letra es
	if (*format == 'c')
	{
		c = va_arg(list, int);
		res = ft_print_char(c);
		if (res == -1)
			return (-1);
		count = count + res;
	}
	else if (*format == '%')
	{
		res = write (1, "%", 1);
		if (res == -1) 
			return (-1); 
		count = res + count;		
	}	
	else if (*format == 's')
	{
		s = va_arg(list, char *);
		res = ft_putstr(s);
		if (res == -1)
			return (-1);
		count = count + res;	
	}
	else if (*format == 'd' || *format == 'i') // funcionan igual de cara a printf
	{
		n = va_arg(list, int);
		res = ft_putnbr(n);
		if (res == -1) 
			return (-1);     
		count = count + res; 
	}
	else if (*format == 'u')
	{
		n2 = va_arg(list, unsigned int);
		res = ft_putnbr(n2);
		if (res == -1) 
			return (-1);     
		count = count + res; 
	}

	void p;
	else if (*format == 'p') // void* - imprime direcciones de memoria en hexadecimal arrancando por 0x
	{
		p = va_arg(list, void *);
		res = ft_printptr((unsigned long long)p);
		if (res == -1) 
			return (-1);     
		count = count + res; 
	}
	else 
    {
        // Manejar error o caso especial (ej. '%%')
    }
	}
	else

	{
	res = write(1, format, 1); // 1. Escribir, usando la dirección de 'format'
	if (res == -1)                 // 2. Verificar el fallo de write()
		return (-1);               //    Retornar -1 en caso de error
	count = count + res;           // 3. Sumar el número de bytes REALES escritos (debería ser 1)
	}
	format++; // Avanzamos al siguiente carácter de la string de formato.
	va_end(list);
	return (count);
	}
}
// dejar en printf las VA - mandar las comprobaciones de if a otra funcion

		// Lógica para %c - crear variable para cada caso
		// 1. Declarar y extraer el argumento (recuerda la promoción a int)
    // 2. Intentar escribir ese argumento, manejando la dirección de memoria
    // 3. Manejar el error de write
    // 4. Actualizar el contador (count)