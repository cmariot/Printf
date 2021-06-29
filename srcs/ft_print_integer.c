/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:23:50 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/29 18:19:02 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_print_integer(t_flags *flags)
{
	int		d;
	char	*str;
	int		len;
	int		backup_precision;

	if (flags->star_flag)
		ft_star_flag(flags);
	d = va_arg(flags->args, int);
	str = ft_itoa(d);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	backup_precision = flags->precision;
	if (flags->field_width && !flags->minus_flag)
		ft_print_space(flags, len);
	backup_precision = flags->precision;
	if (flags->dot_flag)
		while (*str && backup_precision--)
			flags->total_lenght += ft_putchar(*str++);
	else
		while (*str)
			flags->total_lenght += ft_putchar(*str++);
	if (flags->field_width && flags->minus_flag)
		ft_print_space(flags, len);
	flags->minus_flag = 0;
	flags->dot_flag = 0;
}
