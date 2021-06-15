/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ret.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:23:12 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/15 15:08:45 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_ret(int n)
{
	long int	nb;
	char		*base_dec;
	int			ret;

	nb = n;
	ret = 0;
	base_dec = "0123456789";
	if (nb < 0)
	{
		ret += write(1, "-", 1);
		nb = -nb;
		ret += ft_putnbr_ret(nb);
		return (ret);
	}
	if ((nb >= 0) && (nb <= 9))
	{
		ret += write(1, &base_dec[nb], 1);
	}
	else
	{
		ret += ft_putnbr_ret(nb / 10);
		ret += write(1, &base_dec[nb % 10], 1);
	}
	return (ret);
}
