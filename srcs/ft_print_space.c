/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 17:05:47 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/20 13:09:26 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_space(t_flags *flags, int len)
{
	char	c;

	if (len < flags->field_width)
	{
		c = ' ';
		while (flags->field_width-- - len)
		{
			flags->total_lenght += write(1, &c, 1);
		}
	}
	flags->field_width = 0;
}
