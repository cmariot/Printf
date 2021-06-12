/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 16:58:06 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/12 15:18:30 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percent_char(const char *format, char c)
{
	if (*format == '%')
	{
		format++;
		if (*format == c)
			return (1);
	}
	return (0);
}

int	ft_percent_percent(const char *format)
{
	if (*format == '%')
	{
		format++;
		if (*format == '%')
			return (1);
	}
	return (0);
}

