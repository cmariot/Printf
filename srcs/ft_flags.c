/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:34:02 by cmariot           #+#    #+#             */
/*   Updated: 2021/07/09 18:21:14 by cmariot          ###   ########.fr       */
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
	flags->pointer = 0;
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
	flags->pointer = 0;
	return (flags);
}

unsigned int	ft_set_prec(unsigned int i, t_flags *flgs, const char *frmt)
{
	flgs->dot = 1;
	i++;
	flgs->precision = 0;
	if (ft_isdigit(frmt[i]))
		while (ft_isdigit(frmt[i]))
			flgs->precision = flgs->precision * 10 + frmt[i++] - '0';
	else if (frmt[i] == '*')
	{
		flgs->star_for_precision = 1;
		i++;
	}
	return (i);
}

unsigned int	ft_set_minus(t_flags *flags)
{
	flags->minus = 1;
	return (1);
}

unsigned int	ft_chck_flgs(const char *frmt, t_flags *flgs, unsigned int i)
{
	while (!ft_is_in_type_list(frmt[i]) && frmt[i])
	{
		if (frmt[i] == '-')
			i += ft_set_minus(flgs);
		else if (frmt[i] == '0')
		{
			flgs->zero = 1;
			i++;
		}
		else if (frmt[i] == '*')
		{
			flgs->star_for_field_width = 1;
			i++;
		}
		else if (ft_isdigit(frmt[i]))
			while (ft_isdigit(frmt[i]))
				flgs->field_width = flgs->field_width * 10 + (frmt[i++] - '0');
		else if (frmt[i] == '.')
			i = ft_set_prec(i, flgs, frmt);
		else
			i++;
	}
	return (i);
}
