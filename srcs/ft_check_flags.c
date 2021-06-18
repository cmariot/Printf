/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:34:02 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/18 17:39:18 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_chck_flgs(const char *frmt, t_flags *flgs, unsigned int i)
{
	i++;
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
	}
	return (i);
}
