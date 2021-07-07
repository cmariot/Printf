/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:50:13 by cmariot           #+#    #+#             */
/*   Updated: 2021/07/07 16:53:04 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*ft_initialize_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->star_for_field_width = 0;
	flags->field_width = 0;
	flags->dot = 0;
	flags->star_for_precision = 0;
	flags->precision = 0;
	flags->total_print = 0;
	flags->minus_printed = 0;
	return (flags);
}

t_flags	*ft_reset_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->star_for_field_width = 0;
	flags->field_width = 0;
	flags->dot = 0;
	flags->star_for_precision = 0;
	flags->precision = 0;
	flags->minus_printed = 0;
	return (flags);
}
