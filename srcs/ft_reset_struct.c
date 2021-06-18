/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 22:58:56 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/18 17:14:50 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*ft_reset_struct(t_flags *flags)
{
	flags->args = 0;
	flags->minus_flag = 0;
	flags->zero_flag = 0;
	flags->dot_flag = 0;
	flags->star_flag = 0;
	flags->field_width = 0;
	flags->type = 0;
	return (flags);
}
