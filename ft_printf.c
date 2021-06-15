/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:55:24 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/15 12:35:36 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	simple_printing(const char *format, va_list va_obj)
{
	int	ret;

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
			else if (*format == 'd')
				ret += ft_putnbr_ret(va_arg(va_obj, int);
		}
		format++;
	}
//	printf("return (%d);\n\n", ret);
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
// 	printf("Test d'affichage de \a \\ \" 'b' \' %% \n");
// 	ft_printf("Test d'affichage de \a - \b - \f - \n - \r - \t - \v - \n");
//	printf("Test d'affichage de \a - \b - \f - \n - \r - \t - \v - \n");
	ft_printf("\nTest d'affichage de char c : %c\n", 'c');
//	printf("Test d'affichage de char c : %c\n", 'c');
	ft_printf("Test d'affichage de char *str : %s\n", "str");
//	printf("Test d'affichage de char *str : %s\n", "str\n");
//	printf("Test d'affichage de l'adresse de *str : %p\n", &str);
	ft_printf("Test d'affichage de int nb : %d\n", 123456789);





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
