/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:23:50 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/24 13:57:57 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_print_integer(t_flags *flags)
{
	int		d;
	char	*str;
	int		len;

	d = va_arg(flags->args, int);
	str = ft_itoa(d);
	len = ft_strlen(str);
	if (flags->field_width && !flags->minus_flag)
		ft_print_space(flags, len);
	while (*str)
	{
		flags->total_lenght += ft_putchar(*str++);
	}
	if (flags->field_width && flags->minus_flag && !flags->dot_flag)
	{
		ft_print_space(flags, len);
		flags->minus_flag = 0;
	}
	flags->dot_flag = 0;
}
