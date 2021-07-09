/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:32:19 by cmariot           #+#    #+#             */
/*   Updated: 2021/07/09 16:08:15 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_field_width(t_flags *flags, int len, char c)
{
	int	i;

	i = 0;
	if (flags->precision < len)
		while ((flags->field_width - flags->precision) - i++)
			flags->total_print += ft_putchar(c);
	else if (flags->field_width > len)
		while (flags->field_width-- - len)
			flags->total_print += ft_putchar(c);
}

void	ft_space_str(t_flags *flags, int len)
{
	char	c;

	if (flags->zero && !flags->minus)
		c = '0';
	else
		c = ' ';
	if (!flags->dot && (flags->field_width >= len))
		while (flags->field_width-- - len)
			flags->total_print += ft_putchar(c);
	else if (flags->dot && (flags->precision >= 0))
	{
		if (flags->field_width >= flags->precision)
			ft_print_field_width(flags, len, c);
		else if (flags->precision >= len)
			if (flags->field_width > len)
				while (flags->field_width-- - len)
					flags->total_print += ft_putchar(c);
	}
	else if (flags->field_width > len)
		while (flags->field_width-- - len)
			flags->total_print += ft_putchar(c);
	flags->field_width = 0;
}

void	ft_print_str(t_flags *flags)
{
	char	*str;
	int		len;
	int		backup_precision;

	if (flags->star_for_field_width)
		ft_field_width_star(flags);
	if (flags->star_for_precision)
		ft_precision_star(flags);
	str = va_arg(flags->args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags->field_width && !flags->minus)
		ft_space_str(flags, len);
	backup_precision = flags->precision;
	if (flags->dot && (flags->precision >= 0))
		while (*str && backup_precision--)
			flags->total_print += ft_putchar(*str++);
	else
		while (*str)
			flags->total_print += ft_putchar(*str++);
	if (flags->field_width && flags->minus)
		ft_space_str(flags, len);
	ft_reset_flags(flags);
}
