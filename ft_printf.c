/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:55:24 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/13 21:47:47 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	simple_printing(const char *format, va_list va_obj)
{
	int	ret;
	int	c;

	ret = 0;
	while (*format)
	{
		if (ft_character_printing(format) == 1)
			ret++;
		else if (ft_percent_char(format, 'c') == 1)
		{
			c = va_arg(va_obj, int);
			ret += ft_putchar_ret(c);
			format++;
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
	ft_printf("\nFonction Printf\n");
//	printf("Fonction Printf\n");
 	ft_printf("Test d'affichage de \a \\ \" 'b' \' %% \n");
 //	printf("Test d'affichage de \a \\ \" 'b' \' %% \n");
 	ft_printf("Test d'affichage de \a - \b - \f - \n - \r - \t - \v - \n");
 //	printf("Test d'affichage de \a - \b - \f - \n - \r - \t - \v - \n");
	ft_printf("Test d'affichage de char c : %c\n", 'c');
//	printf("Test d'affichage de char c : %c\n", 'c');
	
	return (0);
}
