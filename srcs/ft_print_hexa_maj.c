/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_maj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:32:19 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/18 17:24:35 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_uitoa_hexa_maj(unsigned int n, t_flags *flags)
{
	char			*base;
	unsigned int	diviseur;
	unsigned int	result;

	base = "0123456789ABCDEF";
	diviseur = 1;
	while ((n / diviseur) >= 16)
		diviseur = diviseur * 16;
	while (diviseur > 0)
	{
		result = (n / diviseur) % 16;
		flags->total_lenght += ft_putchar(base[result]);
		diviseur = diviseur / 16;
	}
}

void	ft_print_hexa_maj(t_flags *flags)
{
	unsigned int	X;

	X = va_arg(flags->args, unsigned int);
	ft_uitoa_hexa_maj(X, flags);
}
