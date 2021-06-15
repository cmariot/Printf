/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ret.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:23:12 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/15 12:35:31 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_ret(int n)
{
	long int	nb;
	char		*base_dec;
	static int			ret;

	nb = n;
	base_dec = "0123456789";
	ret = 0;
	if (nb < 0)
	{
		ret += write(1, "-", 1);
		nb = -nb;
	}
	if ((nb >= 0) && (nb <= 9))
	{
		ret += write(1, &base_dec[nb], 1);
	}
	else
	{
		ft_putnbr_ret(nb / 10);
		ret += write(1, &base_dec[nb % 10], 1);
	}
	return (ret);
}

int	main(void)
{
	int ret;
	char c;

	c = '\n';
	ret = 0;
	ret += ft_putnbr_ret(-999);
	write(1, &c, 1);
	ret += ft_putnbr_ret(999);
	write(1, &c, 1);
	ft_putnbr_ret(ret);	
	write(1, &c, 1);
	return (0);
}
