/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:23:50 by cmariot           #+#    #+#             */
/*   Updated: 2021/07/05 13:31:26 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_space_for_integer(t_flags *flags, int len)
{
	char	c;
	int		i;

	c = ' ';
	i = 0;
	if (flags->field_width)
	{
		if (len > flags->precision)
		{
			if (flags->field_width > len)
				while ((flags->field_width - len) - i++)
					flags->total_print += write(1, &c, 1);
		}
		else if (flags->precision > len)
		{
			if (flags->field_width > flags->precision)
				while ((flags->field_width - flags->precision) - i++)
					flags->total_print += write(1, &c, 1);
		}
		else if (len < flags->field_width)
			while (flags->field_width-- - len)
				flags->total_print += write(1, &c, 1);
	}
	flags->field_width = 0;
}

void	ft_treat_integer(char *str, t_flags *flags)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	if (flags->field_width && !flags->minus)
		ft_print_space_for_integer(flags, len);
	if (flags->dot)
	{
		i = 0;
		if (flags->precision && (len < flags->precision))
		{
			if (*str == '-' && flags->precision)
			{
				flags->total_print += ft_putchar(*str++);
				// Pas sur du i ici
				i--;
			}
			while ((flags->precision - len) - i++)
				// Ici a corriger, afficher des espaces si fw ?
				flags->total_print += ft_putchar('0');
		}
		else if (!flags->precision)
			while (*str == '0')
				str++;
		while (*str)
			flags->total_print += ft_putchar(*str++);

	}
	else
		while (*str)
			flags->total_print += ft_putchar(*str++);
	if (flags->field_width && flags->minus)
		ft_print_space_for_integer(flags, len);
	flags->minus = 0;
	flags->zero = 0;
}

void	ft_print_integer(t_flags *flags)
{
	int		d;
	char	*str;

	if (flags->star_for_field_width)
		ft_field_width_star(flags);
	if (flags->star_for_precision)
		ft_precision_star(flags);
	d = va_arg(flags->args, int);
	str = ft_itoa(d);
	ft_treat_integer(str, flags);
	free(str);
}
