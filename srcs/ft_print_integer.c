/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:23:50 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/30 14:53:26 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_treat_integer(char *str_from_itoa, t_flags *flags)
{
	int len;
	int	backup_precision;

	len = ft_strlen(str_from_itoa);
	if (flags->field_width && !flags->minus_flag)
		ft_print_space(flags, len);
	backup_precision = flags->precision;
	if (flags->dot_flag)
	{
		if (*str_from_itoa == '-')
		{
			flags->total_lenght += ft_putchar(*str_from_itoa++);
			len--;
		}
		if (len < flags->precision)
			while (flags->precision - len++)
				flags->total_lenght += ft_putchar('0');
		while (*str_from_itoa && backup_precision--)
			flags->total_lenght += ft_putchar(*str_from_itoa++);
	}
	else
		while (*str_from_itoa)
			flags->total_lenght += ft_putchar(*str_from_itoa++);
	if (flags->field_width && flags->minus_flag)
		ft_print_space(flags, len);
	flags->minus_flag = 0;
	flags->dot_flag = 0;
	return ;
}


void	ft_print_integer(t_flags *flags)
{
	int		d;
	char	*str;

	if (flags->star_flag)
		ft_star_flag(flags);
	d = va_arg(flags->args, int);
//	printf("d = %d\n", d);
	str = ft_itoa(d);
//	printf("str = %s\n", str);
	ft_treat_integer(str, flags); 
	free(str);
	return ;
}
