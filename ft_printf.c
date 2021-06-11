/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:55:24 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/11 14:44:00 by cmariot          ###   ########.fr       */
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

// https://perso.liris.cnrs.fr/raphaelle.chaine/COURS/LIFAP6/printf_form.html

int	pourcent_char(const char *str, char c)
{
	if (*str == '%')
		str++;
		if (*str == c)
			return (0);
	return (1);
}

int	ft_putchar_ret(char c)
{
	write(1, &c, 1);
	return (1);
}

int	int_len(int n)
{
	int	n_len;

	n_len = 0;
	while (n != 0)
	{
		n = n / 10;
		n_len++;
	}
	return (n_len);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	int ret;

	if (s)
	{
		ret = ft_strlen(s);
		while (*s)
			write(1, s++, 1);
		return (ret);
	}
	else
		return (0);
}

int		ft_check_base(char *base)
{
	int			base_len;
	int			j;

	base_len = 0;
	while (base[base_len] != '\0')
	{
		if (base[base_len] == '+' || base[base_len] == '-')
			return (0);
		j = base_len + 1;
		while (base[j] != '\0')
		{
			if (base[base_len] == base[j])
				return (0);
			j++;
		}
		base_len++;
	}
	if (base_len <= 1)
		return (0);
	return (1);
}

int	ft_putnbr_base(int nbr, char *base)
{
	int			diviseur;
	int			result;
	int			base_len;
	long int	long_nb;
	int 		ret;

	ret = 0;
	if (ft_check_base(base) == 0)
		return 0;
	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	long_nb = nbr + 0;
	if (nbr < 0)
	{
		ft_putchar('-');
		long_nb = -(long_nb);
	}
	diviseur = 1;
	while ((long_nb / diviseur) >= base_len)
		diviseur = diviseur * base_len;
	while (diviseur > 0)
	{
		result = (long_nb / diviseur) % base_len;
		ret += ft_putchar_ret(base[result]);
		diviseur = diviseur / base_len;
	}
	return (ret);
}

int		print(const char *format, va_list va_obj)
{
	int				ret;
	int				d;
	char			*s;
	unsigned char	c;
	unsigned int	x;
	unsigned int	X;

	ret = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ret += ft_putchar_ret(*format);
		}
		else if (pourcent_char(format, 'c') == 0)
		{
			c = va_arg(va_obj, int);
			ret += ft_putchar_ret(c);
			format++;
		}
		else if (pourcent_char(format, 's') == 0)
		{
			s = va_arg(va_obj, char *);
			ret += ft_putstr(s);
			format++;
		}
		else if (pourcent_char(format, 'p') == 0)
		{

		}
		else if (pourcent_char(format, 'd') == 0)
		{
			d = va_arg(va_obj, int);
			ft_putnbr(d);
			format++;
			ret += int_len(d);
		}
		else if (pourcent_char(format, 'i') == 0)
		{

		}
		else if (pourcent_char(format, 'u') == 0)
		{

		}
		else if (pourcent_char(format, 'x') == 0)
		{
			x = va_arg(va_obj, unsigned int);
			ret += ft_putnbr_base(x, "0123456789abcdef");
			format++;
		}
		else if (pourcent_char(format, 'X') == 0)
		{
			X = va_arg(va_obj, unsigned int);
			ret += ft_putnbr_base(x, "0123456789ABCDEF");
			format++;
		}
		else
		{
			ft_putchar('%');
			format++;
		}
		format++;
	}
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list		va_obj;
	int			result;

	va_start(va_obj, format);
	result = print(format, va_obj);
	va_end(va_obj);
	return (result);
}

int 	main(void)
{
	ft_printf("\nFonction Printf\n");
	return (0);
}
