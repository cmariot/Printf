/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:23:50 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/17 20:00:01 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*special_case_itoa(int n)
{
	char	*str;

	if (n == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	else if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	else
		return (NULL);
}

static int	int_len(int n)
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

static char	*int_to_array(int signe, char *nombre, int n, int n_len)
{
	nombre[n_len] = '\0';
	if (signe == 1)
		nombre[0] = '-';
	while (n != 0)
	{
		nombre[n_len - 1] = '0' + n % 10;
		n = n / 10;
		n_len--;
	}
	return (nombre);
}

static char	*ft_itoa(int n)
{
	int		n_len;
	char	*nombre;
	int		signe;
	char	*special_case;

	special_case = special_case_itoa(n);
	if (special_case != NULL)
		return (special_case);
	n_len = int_len(n);
	signe = 0;
	if (n < 0)
	{
		n = -n;
		signe++;
		n_len++;
	}
	nombre = malloc(sizeof(char) * (n_len + signe));
	if (nombre == NULL)
		return (NULL);
	nombre = int_to_array(signe, nombre, n, n_len);
	return (nombre);
}

void ft_print_integer(t_flags *flags)
{
	int d;
	char *str;

	d = va_arg(flags->args, int);
	str = ft_itoa(d);
	while (*str)
	{
		flags->total_lenght += ft_putchar(*str++);
	}

}
