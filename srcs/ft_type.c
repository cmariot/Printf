/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:26:17 by cmariot           #+#    #+#             */
/*   Updated: 2021/07/09 12:00:22 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_in_type_list(int c)
{
	if (c == 'c')
		return (1);
	else if (c == 's')
		return (2);
	else if (c == 'p')
		return (3);
	else if (c == 'd')
		return (4);
	else if (c == 'i')
		return (5);
	else if (c == 'u')
		return (6);
	else if (c == 'x')
		return (7);
	else if (c == 'X')
		return (8);
	else if (c == '%')
		return (9);
	else
		return (0);
}

void	ft_chck_type(const char *frmt, unsigned int i, t_flags *flgs)
{
	if (frmt[i] == 'c')
		ft_print_char(flgs);
	else if (frmt[i] == 'd' || frmt[i] == 'i')
		ft_print_integer(flgs);
	else if (frmt[i] == 's')
		ft_print_str(flgs);
	else if (frmt[i] == 'p')
		ft_print_addr(flgs);
	else if (frmt[i] == 'u')
		ft_print_unsigned_int(flgs);
	else if (frmt[i] == 'x')
		ft_print_hexa(flgs);
	else if (frmt[i] == 'X')
		ft_print_hexa_maj(flgs);
	else if (frmt[i] == '%')
		flgs->total_print += ft_putchar('%');
	return ;
}
