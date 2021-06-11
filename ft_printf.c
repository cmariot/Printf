/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:55:24 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/11 18:29:36 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

/*
 * Description : The printf function writes outpout to stdout, the standard outpout stream. 
 * It writes the outpout under the control of a format string that specifies how subsequent arguments are converted for outpout.
 * The format string is composed of zero or more directives : 
 * - Orginary characters (not %), which are copied unchanged to the outpout stram.
 * - Conversion specifications, each of which results in fetching zero or more subsequent arguments. Each conversion specification is introduced by the % character. The arguments must correspond properly with the conversion specifier.
 *
 * Conversion specification list :
 * - %c : The int argument is converted to an unsigned char, and the resulting character is written.
 * - %s : The string is written without the '\0' character.
 * - %p : 
 * - %d : Is converted to an int and the function prints the number whith it sign if it's negative. 
 * - %i : 
 * - %u : 
 * - %x : 
 * - %X : 
 * - % : The function prints %.
 *
 * The function may be called with a varying number of arguments of varying types. 
 * 
 * Return value : The printf function returns the number of characters printed (not including the trailing '\0' used to end outpout to strings) and a negative value if an error occurs.
 *
 */

int	print(const char *format, va_list va_obj)
{
	int	ret;
	int	c;

	ret = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ret += ft_putchar_ret(*format);
		}
		else if (ft_pourcent_char(format, 'c') == 1)
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
	ret = print(format, va_obj);
	va_end(va_obj);
	return (ret);
}

int 	main(void)
{
	ft_printf("Fonction Printf\n");
	ft_printf("%c - Test d'affichage de char c\n", '1');
	
	return (0);
}
