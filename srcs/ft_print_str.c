/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:32:19 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/30 20:02:39 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		ft_print_space(flags, len);
	backup_precision = flags->precision;
	if (flags->dot)
		while (*str && backup_precision--)
			flags->total_print += ft_putchar(*str++);
	else
		while (*str)
			flags->total_print += ft_putchar(*str++);
	if (flags->field_width && flags->minus)
		ft_print_space(flags, len);
	flags->minus = 0;
	flags->dot = 0;
}
