/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 17:05:47 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/30 13:37:22 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_space(t_flags *flags, int len)
{
	char	c;
	
	c = ' ';
	if (flags->field_width)
	{
		if (flags->dot_flag)
		{
			if (flags->precision < flags->field_width)
			{
				if (len < flags->precision)
					while (flags->field_width-- - len)
						flags->total_lenght += write(1, &c, 1);
				else
					while (flags->field_width-- - flags->precision)
						flags->total_lenght += write(1, &c, 1);
			}
		}
		else if (len < flags->field_width)
			while (flags->field_width-- - len)
						flags->total_lenght += write(1, &c, 1);
	}
	flags->field_width = 0;
}
