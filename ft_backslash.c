/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backslash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 21:55:42 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/11 22:54:02 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_backslash_pourcent(const char *format)
{
	if (*format == '\b')
	{
		printf("Backslash\n");
		format++;
		if (*format == '%')
		{
			ft_putchar_ret('%');
			return (1);
		}
	}
	return (0);
}
