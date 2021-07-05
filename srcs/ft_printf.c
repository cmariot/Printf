/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 23:26:05 by cmariot           #+#    #+#             */
/*   Updated: 2021/07/05 18:25:38 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_flags			*flags;
	unsigned int	i;
	int				result;

	flags = malloc(sizeof(t_flags));
	if (flags == NULL)
		return (-1);
	va_start(flags->args, format);
	flags = ft_initialize_flags(flags);
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			flags->total_print += ft_putchar(format[i]);
		else if (format[i++] == '%')
		{
			i = ft_chck_flgs(format, flags, i);
			ft_chck_type(format, i, flags);
		}
		i++;
	}
	result = flags->total_print;
	free(flags);
	va_end(flags->args);
	return (result);
}
