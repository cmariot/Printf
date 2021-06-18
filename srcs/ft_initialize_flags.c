/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:50:13 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/18 17:00:20 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*ft_initialize_flags(t_flags *flags)
{
	flags->minus_flag = 0;
	flags->zero_flag = 0;
	flags->dot_flag = 0;
	flags->star_flag = 0;
	flags->field_width = 0;
	flags->type = 0;
	flags->total_lenght = 0;
	return (flags);
}
