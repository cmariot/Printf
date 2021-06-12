/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character_printing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 14:23:21 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/12 15:19:01 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_character_printing(const char *format)
{
	int ret;

	ret = 0;
	if (*format != '%')
		ret += ft_putchar_ret(*format);
	else if (ft_percent_percent(format) == 1)
	{
		ret += ft_putchar_ret('%');
		format++;
	}
	return (ret);
}
