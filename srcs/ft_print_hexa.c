/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:32:19 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/30 19:58:20 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_uitohexa_len(unsigned int n)
{
	unsigned int	n_len;
	unsigned int	diviseur;

	n_len = 0;
	diviseur = 1;
	while ((n / diviseur) >= 16)
		diviseur = diviseur * 16;
	while (diviseur > 0)
	{
		n_len++;
		diviseur = diviseur / 16;
	}
	return (n_len);
}

void	ft_uitoa_hexa(unsigned int n, t_flags *flags)
{
	char			*base;
	unsigned int	diviseur;
	unsigned int	result;

	base = "0123456789abcdef";
	diviseur = 1;
	while ((n / diviseur) >= 16)
		diviseur = diviseur * 16;
	while (diviseur > 0)
	{
		result = (n / diviseur) % 16;
		flags->total_print += ft_putchar(base[result]);
		diviseur = diviseur / 16;
	}
}

void	ft_print_hexa(t_flags *flags)
{
	unsigned int	x;
	int				len;

	x = va_arg(flags->args, unsigned int);
	len = ft_uitohexa_len(x);
	if (flags->field_width && !flags->minus)
		ft_print_space(flags, len);
	ft_uitoa_hexa(x, flags);
	if (flags->field_width && flags->minus && !flags->dot)
	{
		ft_print_space(flags, len);
		flags->minus = 0;
	}
	flags->dot = 0;
}
