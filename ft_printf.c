int	ft_printf(char const *, ...)
{
va_list list;
int count;
int res;
int c;

count  = 0;

va_start(list, format)
while (*format) // *format != '\0'
{
	if(*format == '%') 
{
	format++; // Avanzamos al especificador
    
	if (*format == 'c')
	{
		c = va_arg(list, int);
		res = write (1, &c, 1);
		if (res == -1) 
			return (-1); 
		count = res + count;
	}
	else if (*format == '%')
	{
		res = write (1, "%", 1);
		if (res == -1) 
			return (-1); 
		count = res + count;		
	}		
		
		// Lógica para %c - crear variable para cada caso
		// 1. Declarar y extraer el argumento (recuerda la promoción a int)
    // 2. Intentar escribir ese argumento, manejando la dirección de memoria
    // 3. Manejar el error de write
    // 4. Actualizar el contador (count)
    }
    else if (*format == 's')
    {
        // Lógica para %s
    }
    else if (*format == 'd')
    {
        // Lógica para %d
    }
		// chequear todos los especificadores que haya
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

// dejar en printf las VA - mandar las comprobaciones de if a otra funcion