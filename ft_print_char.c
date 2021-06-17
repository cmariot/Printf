/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:32:19 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/17 19:32:45 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(t_flags *flags)
{
	char c;

	c = va_arg(flags->args, int);
//	if (flags->wdt && !flags->minus)
	flags->total_lenght += write(1, &c, sizeof(c));
//	if (flags->wdt && flags->minus)
}
