/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:26:17 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/24 13:58:05 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		flgs->total_lenght += ft_putchar('%');
	else
		return ;
}
