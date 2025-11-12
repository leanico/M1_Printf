#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int ret1;
	int ret2;
	char c = 'A';
	char *str = "Hola, printf!";
	int num = -42;
	unsigned int unum = 424242;
	void *ptr = &num;

	printf("=== TEST DE ft_printf ===\n\n");

	// %c
	ret1 = ft_printf("Mi char: %c\n", c);
	ret2 = printf("Oficial:  %c\n\n", c);

	// %s
	ret1 = ft_printf("Mi string: %s\n", str);
	ret2 = printf("Oficial:   %s\n\n", str);

	// %d y %i
	ret1 = ft_printf("Mi decimal: %d\n", num);
	ret2 = printf("Oficial:    %d\n\n", num);

	ret1 = ft_printf("Mi entero con %%i: %i\n", num);
	ret2 = printf("Oficial con %%i:    %i\n\n", num);

	// %u
	ret1 = ft_printf("Mi unsigned: %u\n", unum);
	ret2 = printf("Oficial:     %u\n\n", unum);

	// %x
	ret1 = ft_printf("Mi hexa minúscula: %x\n", unum);
	ret2 = printf("Oficial:           %x\n\n", unum);

	// %X
	ret1 = ft_printf("Mi hexa MAYÚSCULA: %X\n", unum);
	ret2 = printf("Oficial:           %X\n\n", unum);

	// %p
	ret1 = ft_printf("Mi puntero: %p\n", ptr);
	ret2 = printf("Oficial:    %p\n\n", ptr);

	// %%
	ret1 = ft_printf("Porcentaje: %%\n");
	ret2 = printf("Oficial:    %%\n\n");

	return (0);
}
