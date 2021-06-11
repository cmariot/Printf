/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pourcent_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 16:58:06 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/11 23:45:35 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pourcent_char(const char *format, char c)
{
	if (*format == '%')
	{
		format++;
		if (*format == c)
			return (1);
	}
	return (0);
}
