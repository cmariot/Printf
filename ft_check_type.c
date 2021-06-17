/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:26:17 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/17 21:26:57 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_type(const char *format, unsigned int i, t_flags *flags)
{
	if (format[i] == 'c')
	{
		ft_print_char(flags);
	}
	else if (format[i] == 'd' || format[i] == 'i')
	{
		ft_print_integer(flags);
	}
	else if (format[i] == 's')
	{
		ft_print_str(flags);
	}
	else if (format[i] == 'p')
	{
	//	ft_print_addr(flags);
	}
	else if (format[i] == 'u')
	{
		ft_print_unsigned_int(flags);
	}
	else if (format[i] == 'x')
	{
		ft_print_hexa(flags);
	}
	else if (format[i] == 'X')
	{
		ft_print_hexa_maj(flags);
	}
	else if (format[i] == '%')
	{
	//	ft_print_percent(flags);
	}
}
