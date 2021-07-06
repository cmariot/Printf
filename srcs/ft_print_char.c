/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:32:19 by cmariot           #+#    #+#             */
/*   Updated: 2021/07/06 12:33:15 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	{
		ft_print_space(flags, 1);
		flags->minus = 0;
	}
}
