/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:34:02 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/25 16:49:50 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_chck_flgs(const char *frmt, t_flags *flgs, unsigned int i)
{
	while (!ft_is_in_type_list(frmt[i]))
	{
		if (frmt[i] == '-')
		{
			flgs->minus_flag = 1;
			i++;
		}
		else if (frmt[i] == '0')
		{
			flgs->zero_flag = 1;
			i++;
		}
		else if (frmt[i] == '.')
		{
			flgs->dot_flag = 1;
			i++;
		}
		else if (frmt[i] == '*')
		{
			flgs->star_flag = 1;
			i++;
		}
		else if (ft_isdigit(frmt[i]))
		{
			while (ft_isdigit(frmt[i]))
			{
				flgs->field_width = flgs->field_width * 10 + frmt[i] - '0';
				i++;
			}
		}
	}
	return (i);
}
