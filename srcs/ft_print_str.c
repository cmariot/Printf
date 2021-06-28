/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:32:19 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/28 10:14:20 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(t_flags *flags)
{
	char	*str;
	int		len;

	if (flags->star_flag)
		ft_star_flag(flags);
	str = va_arg(flags->args, char *);
	len = ft_strlen(str);
	if (flags->field_width && !flags->minus_flag)
		ft_print_space(flags, ft_strlen(str));
	if (flags->dot_flag)
	{
		return ;
	}
	while (*str)
		flags->total_lenght += ft_putchar(*str++);
	if (flags->field_width && flags->minus_flag && !flags->dot_flag)
		ft_print_space(flags, len);
	flags->minus_flag = 0;
	flags->dot_flag = 0;
}
