/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:34:02 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/17 18:41:29 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_check_flags(const char *format, t_flags *flags, unsigned int i)
{
	i++;
	while (!ft_is_in_type_list(format[i]))
	{
		if (format[i] == '-')
		{
			flags->minus_flag = 1;
			i++;
		}
		else if (format[i] == '0')
		{
			flags->zero_flag = 1;
			i++;
		}
		else if (format[i] == '.')
		{
			flags->dot_flag = 1;
			i++;
		}
		else if (format[i] == '*')
		{
			flags->star_flag = 1;
			i++;
		}
	}
	return (i);
}
