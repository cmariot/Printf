/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:23:50 by cmariot           #+#    #+#             */
/*   Updated: 2021/07/05 18:47:21 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_space_before_integer(t_flags *flags, int len, char *str)
{
	char	c;
	int		i;

	// The number of spaces to print before the integer is influenced by :
	// - The field_width given
	// 		. If fw > len or precision
	// 		. If the zero flag is present we print 0 and not spaces
	// 		. 

	if (flags->zero && !flags->minus)
	{
		c = '0';
		if (*str == '-')
		{
			flags->total_print += ft_putchar('-');
			flags->minus_printed = 1;
		}
	}
	else
		c = ' ';
	i = 0;
	if (flags->field_width > flags->precision)
	{
		if (len < flags->field_width)
		{
			if (flags->field_width > flags->precision)
				while (flags->field_width-- - len)
					flags->total_print += write(1, &c, 1);
		}
		else if (len > flags->precision)
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
		flags->field_width = 0;
	}
}

void	ft_space_after_integer(t_flags *flags, int len)
{
	int		i;
	char	c;

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
	return ;
}

void	ft_treat_integer(char *str, t_flags *flags)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	if (flags->field_width && !flags->minus)
		ft_space_before_integer(flags, len, str);
	if (flags->dot)
	{
		i = 0;
		if (flags->precision && (len < flags->precision))
		{
			if (*str == '-' && flags->precision)
			{
				flags->total_print += ft_putchar('-');
				flags->minus_printed = 1;
			}
			while ((flags->precision - len) - i++)
				flags->total_print += ft_putchar('0');
		}
		else if (!flags->precision)
			while (*str == '0')
				str++;
	}
	if (flags->minus_printed)
		str++;
	while (*str)
		flags->total_print += ft_putchar(*str++);
	if (flags->field_width && flags->minus)
		ft_space_after_integer(flags, len);
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
