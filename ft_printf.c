/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:55:24 by cmariot           #+#    #+#             */
/*   Updated: 2021/05/25 21:29:43 by cmariot          ###   ########.fr       */
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
 * - %s : The  
 * - %p : 
 * - %d : 
 * - %i : 
 * - %u : 
 * - %x : 
 * - %X : 
 * - %% ???
 *
 * The function may be called with a varying number of arguments of varying types. 
 * 
 * Return value : The printf function returns the number of characters printed (not including the trailing '\0' used to end outpout to strings) and a negative value if an error occurs.
 *
 */

int	pourcent_d(const char *str)
{
	if (*str == '%')
		str++;
		if (*str == 'd')
			return (0);
	return (1);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putnbr(int n)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if ((nb >= 0) && (nb <= 9))
	{
		ft_putchar(nb + '0');
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}

int		print(const char *format, va_list va_obj)
{
	int	ret;
	int	d;

	ret = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			ret++;
		}
		else if (pourcent_d(format) == 0)
		{
			d = va_arg(va_obj, int);
			ft_putnbr(d);
			format++;
			//ret ++ len_int
		}
		format++;
	}
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list va_obj;
	int	result;

	va_start(va_obj, format);
	result = print(format, va_obj);
	va_end(va_obj);
	return (result);
}

// man 3 stdarg / example
void 	foo(char *fmt, ...)
{
	   va_list ap, ap2;
	   int d;
	   char c, *s;

	   va_start(ap, fmt);
	   va_copy(ap2, ap);
	   while (*fmt)
			   switch(*fmt++) {
			   case 's':                       /* string */
					   s = va_arg(ap, char *);
					   printf("string %s\n", s);
					   break;
			   case 'd':                       /* int */
					   d = va_arg(ap, int);
					   printf("int %d\n", d);
					   break;
			   case 'c':                       /* char */
					   /* Note: char is promoted to int. */
					   c = va_arg(ap, int);
					   printf("char %c\n", c);
					   break;
			   }
	   va_end(ap);
	   /* use ap2 to iterate over the arguments again */
	   va_end(ap2);
}


int 	main(void)
{
	float nb;
	int result;

	nb = 134.03725763;
	result = ft_printf("Charl%d\n", nb);
	ft_putnbr(result);
	result = printf("\n  %1.4f  \n", nb);
	ft_putnbr(result);
	return (0);
}
