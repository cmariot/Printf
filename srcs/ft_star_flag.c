/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 17:27:15 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/19 17:27:20 by cmariot          ###   ########.fr       */
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
