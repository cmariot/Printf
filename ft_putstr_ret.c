/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_ret.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:41:49 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/14 13:47:33 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_ret(const char *format)
{
	int	ret;

	ret = 0;
	if (format)
	{
		while (*format)
		{
			ret += ft_putchar_ret(*format++);
		}
	}
	return (ret);
}
