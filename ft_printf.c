/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:55:24 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/11 23:20:20 by cmariot          ###   ########.fr       */
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
		if (*format != '%')
		{
			ret += ft_putchar_ret(*format);
		}
		else if (ft_backslash_pourcent(format))
		{
			ret++;
		}
		else if (ft_pourcent_char(format, 'c') == 1)
		{
			c = va_arg(va_obj, int);
			ret += ft_putchar_ret(c);
			format++;
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
//	ft_printf("Fonction Printf\n");
//	ft_printf("Test d'affichage de char c : %c\n", 'c');
 	ft_printf("Test d'affichage de \a \\ \" 'b' \' % \% \n");
 	printf("Test d'affichage de \a \\ \" 'b' \' % \% \n");
	
	return (0);
}
