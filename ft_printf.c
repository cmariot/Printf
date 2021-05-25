/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:55:24 by cmariot           #+#    #+#             */
/*   Updated: 2021/05/25 11:30:24 by cmariot          ###   ########.fr       */
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

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	if (c < 0 || c > 127)
		return (NULL);
	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	if (str[i] == '\0' && c == '\0')
		return (&str[i]);
	return (NULL);
}

int		pourcent_d(const char *str)
{
	if (*str == '%')
		str++;
		if (*str == 'd')
			return (0);
	return (1);
}


int		ft_printf(const char *format, ...)
{
	va_list va_obj;
	char c;

	va_start(va_obj, format);
	while (*format)
	{
		if (pourcent_d(format))
		{
			c = va_arg(va_obj, int);
			printf("%d\n", c);
		}
		else 
			write(1, format, 1);
		format++;
	}
	va_end(va_obj);
	return (0);
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
	int nb;

	nb = 5;
	ft_printf("S%dalu:t\n", nb, c);
//	ft_printf("Salut\n");

	return (0);
}
