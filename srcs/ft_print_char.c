/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:32:19 by cmariot           #+#    #+#             */
/*   Updated: 2021/07/09 15:29:30 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	if (c)
	{
		write(1, &c, 1);
		return (1);
	}
	else
		return (0);
}

void	ft_print_space(t_flags *flags, int len)
{
	char	c;

	if (flags->zero && !flags->minus)
		c = '0';
	else
		c = ' ';
	if (flags->field_width)
	{
		if (flags->dot)
		{
			if (flags->precision < flags->field_width)
			{
				if (len < flags->precision)
					while (flags->field_width-- - len)
						flags->total_print += write(1, &c, 1);
				else
					while (flags->field_width-- - flags->precision)
						flags->total_print += write(1, &c, 1);
			}
		}
		else if (len < flags->field_width)
			while (flags->field_width-- - len)
				flags->total_print += write(1, &c, 1);
	}
	flags->field_width = 0;
}

void	ft_print_char(t_flags *flags)
{
	char	c;

	if (flags->star_for_field_width)
		ft_field_width_star(flags);
	c = va_arg(flags->args, int);
	if (flags->field_width && !flags->minus)
		ft_print_space(flags, 1);
	flags->total_print += write(1, &c, 1);
	if (flags->field_width && flags->minus)
		ft_print_space(flags, 1);
	ft_reset_flags(flags);
}
