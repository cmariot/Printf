/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:55:24 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/17 14:23:10 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		va_obj;
	t_flags		flags;

	va_start(va_obj, format);
	while (*format)
	{
		if (*format != '%')
				 flags.already_print += ft_putchar((int)*format++);
		else if (*format == '%')
		{
			format++;
			while (!ft_is_in_type_list(*format))
			{
				if (ft_is_in_flags_list(*format))
				{
					printf("\nflag = %d\n", ft_is_in_flags_list(*format));
				}
				format++;
			}
			flags.type = ft_is_in_type_list(*format);
			printf("\ntype = %d\n", flags.type);
			format++;
		}
	}
	va_end(va_obj);
	return (flags.already_print);
}

int 	main(void)
{
	int ret;

	ret = ft_printf("test12345 %0i");
	printf("\nretour = %d\n", ret);
	return (0);
}
