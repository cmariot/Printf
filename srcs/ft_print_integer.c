/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:23:50 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/30 20:06:05 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_treat_integer(char *str, t_flags *flags)
{
	int len;
	int	backup_precision;

	len = ft_strlen(str);
	if (flags->zero && *str == '-')
	{
		flags->total_print += ft_putchar(*str++);
		len--;
	}
	if (flags->field_width && !flags->minus)
		ft_print_space(flags, len);
	backup_precision = flags->precision;
	if (flags->dot)
	{
		if (*str == '-')
		{
			flags->total_print += ft_putchar(*str++);
			len--;
		}
		if (len < flags->precision)
			while (flags->precision - len++)
				flags->total_print += ft_putchar('0');
		while (*str && backup_precision--)
			flags->total_print += ft_putchar(*str++);
	}
	else
		while (*str)
			flags->total_print += ft_putchar(*str++);
	if (flags->field_width && flags->minus)
		ft_print_space(flags, len);
	flags->minus = 0;
	flags->dot = 0;
	return ;
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
	return ;
}
