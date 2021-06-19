/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:32:19 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/19 16:22:10 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_star_flag(t_flags *flags)
{
	flags->field_width = va_arg(flags->args, int);
	if (flags->field_width < 0)
	{
		flags->field_width = -flags->field_width;
		flags->minus_flag = 1;
	}
	flags->star_flag = 0;
}

void	ft_print_space(t_flags *flags, int len)
{
	char	c;

	c = ' ';
	while (flags->field_width-- - len)
	{
		flags->total_lenght += write(1, &c, 1);
	}
}

void	ft_print_char(t_flags *flags)
{
	char	c;

	if (flags->star_flag)
		ft_star_flag(flags);
	c = va_arg(flags->args, int);
	if (flags->field_width && !flags->minus_flag)
		ft_print_space(flags, 1);
	flags->total_lenght += write(1, &c, 1);
	if (flags->field_width && flags->minus_flag)
	{
		ft_print_space(flags, 1);
		flags->minus_flag = 0;
	}
}
