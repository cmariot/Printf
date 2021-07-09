/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:30:08 by cmariot           #+#    #+#             */
/*   Updated: 2021/07/09 18:17:32 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_percent(t_flags *flags)
{
	if (flags->star_for_field_width)
		ft_field_width_star(flags);
	if (flags->field_width && !flags->minus)
		ft_print_space(flags, 1);
	flags->total_print += ft_putchar('%');
	if (flags->field_width && flags->minus)
		ft_print_space(flags, 1);
	ft_reset_flags(flags);
}
