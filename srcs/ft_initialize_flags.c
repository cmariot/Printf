/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:50:13 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/18 13:58:12 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*ft_initialize_flags(t_flags *flags)
{
//	flags->args = 0;		// Arg to print out
	flags->minus_flag = 0;		// -
	flags->zero_flag = 0;		// 0
	flags->dot_flag = 0;		// .
	flags->star_flag = 0;		// *
	flags->field_width = 0;		// Largeur champ
	flags->type = 0;		// Specificateur
	flags->total_lenght = 0;	// Return value
	return (flags);
}
