/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:55:24 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/15 15:08:04 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	simple_printing(const char *format, va_list va_obj)
{
	int	ret;
	char *str;
//	int nb;

	str = NULL;
	ret = 0;
	while (*format)
	{
		if (ft_character_printing(format) == 1)
			ret++;
		else if (*format == '%')
		{
			format++;
			if (*format == 'c')
				ret += ft_putchar_ret(va_arg(va_obj, int));
			else if (*format == 's')
				ret += ft_putstr_ret(va_arg(va_obj, char *));
		//	else if (*format == 'p')
		//		ret += ft_putadr_ret(va_arg(va_obj, void*));
			else if (*format == 'd' || *format == 'i')
			{
				str = ft_itoa(va_arg(va_obj, int));
				ret += ft_putstr_ret(str);
				free(str);
				str = NULL;
			}
			else if (*format == 'u')
			{}
			else if (*format == 'x')
			{}
			else if (*format == 'X')
			{}
			else if (*format == '%')
				ret += ft_putchar_ret('%');
		}
		format++;
	}
	printf("return (%d);\n\n", ret);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list		va_obj;
	int			ret;

	va_start(va_obj, format);
	ret = simple_printing(format, va_obj);
	va_end(va_obj);
	return (ret);
}

int 	main(void)
{
	char *str;
	char **ptr_str;

	str = "toto\n";
	ptr_str = &str;

//	ft_printf("\nFonction Printf\n");
//	printf("Fonction Printf\n");
// 	ft_printf("Test d'affichage de \a \\ \" 'b' \' %% \n");
// 	   printf("Test d'affichage de \a \\ \" 'b' \' %% \n");
// 	ft_printf("Test d'affichage de \a - \b - \f - \n - \r - \t - \v - \n");
//	   printf("Test d'affichage de \a - \b - \f - \n - \r - \t - \v - \n");
//	ft_printf("\nTest d'affichage de char c : %c\n", 'c');
//	   printf("Test d'affichage de char c : %c\n", 'c');
//	ft_printf("Test d'affichage de char *str : %s\n", "str");
//	   printf("Test d'affichage de char *str : %s\n", "str\n");

//	printf("Test d'affichage de l'adresse de *str : %p\n", &str);

//	ft_printf("Test d'affichage de int nb (d) : %d\n", 123456789);
//	printf("Test retour = %d\n", ft_printf("Test retour de int nb : %d, %d, %d\n", 23512, -12, -20));
	
//	ft_printf("Test d'affichage de int nb (i) : %i\n", 123456789);
//	printf("Test d'affichage de int nb (i) : %i\n", 123456789);

printf("%u\n", -2147483647);
printf("%u\n", -21);
printf("%u\n", -2);
printf("%u\n", 0);
printf("%u\n", 2);
printf("%u\n", 21);
printf("%u\n", 2147483647);



//	printf("Format %-d\n", 6);	
//	printf("Format %0d\n", 6);	
//	printf("Format %.d\n", 6);	
//	printf("Format %*d\n", 6, 6);	
	
//	printf("Format %-3d\n", 6);	
//	printf("Format %03d\n", 6);	
//	printf("Format %.3d\n", 6);	
//	printf("Format %*d\n", 6, 6);
//	printf("%%\n");

	return (0);
}
